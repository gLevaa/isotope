#include "logger.h"

std::string c_logger::prefix = "[~] =";
std::chrono::steady_clock::time_point c_logger::previous_call = std::chrono::steady_clock::now();

void c_logger::log(const std::string& message, bool time) 
{
#ifndef NDEBUG
	if (time)
		std::cout << (prefix + " " + message + " ").c_str() <<
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - c_logger::previous_call).count() <<
		"ms passed" << std::endl;
	else
		std::cout << (prefix + " " + message + " ").c_str() << std::endl;

	previous_call = std::chrono::steady_clock::now();
#endif
}

void c_logger::error(const  std::string& message) 
{
#ifndef NDEBUG
	std::cout << (c_logger::prefix + " " + message + " ").c_str() << 
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - c_logger::previous_call).count() << 
		  "ms passed" << std::endl;
#endif
}