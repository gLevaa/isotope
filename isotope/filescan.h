#pragma once

#ifndef _H_FILESCAN_
#define _H_FILESCAN_

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::experimental::filesystem;

class c_filescan 
{
public:
	static void scan();

	static std::vector<fs::v1::path> files;

private:
	static void init_drives();
	static bool is_encryptable(std::string files);

	static std::vector<std::string> drives;

	static int file_amount;
};

#endif