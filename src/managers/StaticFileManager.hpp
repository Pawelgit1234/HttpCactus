#pragma once

#include <string>
#include <fstream>
#include <map>
#include <sstream>

#include "../utils/Logger.hpp"

namespace hc
{
	namespace manager
	{
		class StaticFileManager
		{
		public:
			StaticFileManager() noexcept;
			~StaticFileManager() noexcept;

			void addStaticFile(const std::string& path);
			std::string getStaticFileContent(const std::string& path);

			void setStaticFolderPath(const std::string& static_base_path) { static_base_path_ = static_base_path; }

		private:
			std::string static_base_path_;
			std::map<std::string, std::string> files_;
		};
	}
}