# isotope
isotope is a ransomware base with full computer scan and file encryption and decryption capabilities.

## Functions
<ul>
  <li>`c_crypto::make_keys()` - generates an an encryption key and IV then assigns it to the `cryptkey key` object.
  <li>`c_crypto::encrypt_file(char* input, char* output)` - takes an input file, encrypts it and outputs the encrypted version to the file provided in `char* output`.</li>
  <li>`c_crypto::decrypt_file(char* input, char* output)` - takes an input file, decrypts it and outputs the decrypted version to the file provided in `char* output`.</li>
  <li>`c_crypto::base64_encode(std::string &input)` - takes an `std::string` and encodes it with base64.</li>
  <li>`c_crypto::base64_decode(std::string &input)` - takes an `std::string` and decodes it from base64 back to its original form.</li>
  <li>`c_filescan::scan()` - scans all files on all drives and saves them to a `std::experimental::filesystem::v1::path` type vector.</li>
  <li>`c_filescan::init_drives()` - gets all drives and saves them to an `std::string` type vector.</li>
</ul>

## Disclaimer
isotope is missing many features, such as a valid payment method or server communications as I do not want this to be used for purposes I do not codone, it is simply here to learn how basic ransomware encrypts your file.

## Libraries
<ul>
  <li>CryptoPP</li>
</ul>
