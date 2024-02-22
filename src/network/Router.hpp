#pragma once

#include <map>
#include <string>

namespace hc
{
	namespace network
	{
		class Router
		{
		public:
			Router() noexcept;
			~Router() noexcept;

			void addUrl(const std::string& url, const std::string& path) { urls_[url] = path; }
			std::string getPath(const std::string& url) { return urls_[url]; }

		private:
			std::map<std::string, std::string> urls_;
		};
	}
}