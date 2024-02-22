#include "StaticFileManager.hpp"

namespace hc
{
	namespace manager
	{
		StaticFileManager::StaticFileManager() noexcept
		{
		}

		StaticFileManager::~StaticFileManager() noexcept
		{
		}

		void StaticFileManager::addStaticFile(const std::string& path)
		{
			std::ifstream file(static_base_path_ + path);

			if (!file.is_open())
			{
				hc::logger::log(path + " can not be added.", hc::logger::LoggerType::WARNING);
				return;
			}

			std::stringstream buffer;
			buffer << file.rdbuf();

			std::string text = buffer.str();
			files_[path] = text;

			hc::logger::log(path + " added.", hc::logger::LoggerType::INFO);
		}

		std::string StaticFileManager::getStaticFileContent(const std::string& path)
		{
			return files_[path];
		}

	}
}