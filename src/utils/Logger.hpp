#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#include "../settings.hpp"

namespace cactus
{
	namespace logger
	{
		enum class LoggerType
		{
			INFO,
			WARNING,
			CRITICAL,
		};

#ifdef WRITE_IN_FILE
		extern bool new_log_file;
#endif // WRITE_IN_FILE


		void log(const std::string& msg, LoggerType msg_type);
	}
}