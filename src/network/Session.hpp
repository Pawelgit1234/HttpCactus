#pragma once

#include <boost\asio.hpp>

#include <memory>

#include "../utils/Logger.hpp"
#include "Request.hpp"
#include "Router.hpp"
#include "../handlers/RequestHandler.hpp"
#include "../managers/StaticFileManager.hpp"

namespace hc
{
	namespace network
	{
		class HttpServer;

		class Session : public std::enable_shared_from_this<Session>
		{
		public:
			Session(boost::asio::io_context& io_context, hc::handler::RequestHandler& request_handler) noexcept;
			~Session() noexcept;

			void start();

		private:
			void doRead();
			void doSend();

			boost::asio::io_context& io_context_;
			boost::asio::ip::tcp::socket socket_;
			
			hc::handler::RequestHandler& request_handler_;
			char data_[hc::settings::BUFFER_SIZE];

			hc::network::Request client_request_;

			friend HttpServer;
		};
	}
}