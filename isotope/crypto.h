#pragma once
#ifndef _H_CRYPTO_
#define _H_CRYPTO_

#include <iostream>

#include "config.h"

#include <cryptopp/rsa.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>

class c_crypto 
{
public:
	struct cryptkey 
	{
		unsigned char enc_key[AES_KEY_SIZE];
		unsigned char enc_iv[AES_KEY_SIZE];
	};

	static std::string base64_encode(std::string &input);
	static std::string base64_decode(std::string &input);

	static void encrypt_file(char* input, char* output);
	static void decrypt_file(char* input, char* output);

	static void make_keys();
	static void random_bytes(const int &amount, unsigned char[AES_KEY_SIZE]);

	static void encrypt_all();
	static void decrypt_all();

	static cryptkey key;
};

#endif