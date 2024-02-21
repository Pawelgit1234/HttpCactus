#include "Logger.hpp"

namespace hc
{
    namespace logger
    {
#ifdef WRITE_IN_FILE
        bool new_log_file = false;
#endif // WRITE_IN_FILE

        void log(const std::string& msg, LoggerType msg_type)
        {
#ifdef ENABLE_LOGGER
            std::string prefix;
            std::string color_code;

            switch (msg_type)
            {
            case LoggerType::INFO:
                prefix = "[INFO]";
                color_code = "\033[0;32m"; // green
                break;
            case LoggerType::WARNING:
                prefix = "[WARNING]";
                color_code = "\033[1;33m"; // yellow
                break;
            case LoggerType::CRITICAL:
                prefix = "[CRITICAL]";
                color_code = "\033[0;31m"; // red
                break;
            default:
                prefix = "[UNKNOWN]";
                color_code = "\033[0m";
                break;
            }

            std::string log_msg = color_code + prefix + " " + msg + "\033[0m";

#ifdef ADD_TIME
            std::time_t current_time;
            std::time(&current_time);
            std::tm local_time;
            localtime_s(&local_time, &current_time);

            char time_buffer[80];
            strftime(time_buffer, 80, "[%d.%m.%Y %H:%M:%S]", &local_time);

            log_msg = std::string(time_buffer) + " " + log_msg;
#endif // ADD_TIME
#ifdef WRITE_IN_FILE
            std::ofstream logfile;

            if (!new_log_file)
            {
                logfile.open("log.txt");
                new_log_file = true;
            }
            else
                logfile.open("log.txt", std::ios_base::app);

            if (logfile.is_open())
            {
                logfile << log_msg << std::endl;
                logfile.close();
            }
            else
                std::cerr << "Error: Unable to open log file!" << std::endl;
#endif // WRITE_IN_FILE
            std::cout << log_msg << std::endl;
#endif // ENABLE_LOGGER
        }
    }
}