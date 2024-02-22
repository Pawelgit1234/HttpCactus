#pragma once

#include <boost\asio.hpp>

#include <string>
#include <thread>

#include "Request.hpp"
#include "Session.hpp"
#include "../utils/Logger.hpp"
#include "Router.hpp"
#include "../handlers/RequestHandler.hpp"
#include "../managers/StaticFileManager.hpp"

namespace hc
{
	namespace network
	{
		class HttpServer final
		{
		public:
			HttpServer() noexcept;
			~HttpServer() noexcept;

			void run();

			void addStaticFolderPath(const std::string& path="static");
			void addFile(const std::string& path, const std::string& url);

		private:
			void startAccept();

			boost::asio::io_context io_context_;
			boost::asio::ip::tcp::acceptor acceptor_;

			hc::network::Router router_;
			hc::handler::RequestHandler request_handler_;
			hc::manager::StaticFileManager static_file_manager_;
		};
	}
}
