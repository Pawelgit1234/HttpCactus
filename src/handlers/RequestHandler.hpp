#pragma once

#include <string>

#include "../network/Request.hpp"
#include "../network/Router.hpp"
#include "../managers/StaticFileManager.hpp"

namespace hc
{
	namespace handler
	{
		class RequestHandler
		{
		public:
			RequestHandler(hc::network::Router& router, hc::manager::StaticFileManager& static_file_manager) noexcept;
			~RequestHandler() noexcept;

			std::string handleRequest(hc::network::Request& request);

		private:
			hc::network::Router& router_;
			hc::manager::StaticFileManager& static_file_manager_;
		};
	}
}