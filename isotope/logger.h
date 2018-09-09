#pragma once
#ifndef _H_LOGGER_
#define _H_LOGGER_

#include <iostream>
#include <chrono>

class c_logger 
{
public:
	static void log(const std::string &message, bool time = true);
	static void error(const std::string &message);

private:
	static std::string prefix;
	static std::chrono::steady_clock::time_point previous_call;
};

#endif