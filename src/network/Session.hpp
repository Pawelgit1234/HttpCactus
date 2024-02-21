#pragma once

#include <boost\asio.hpp>

#include <memory>

#include "../utils/Logger.hpp"
#include "Request.hpp"

namespace hc
{
	namespace network
	{
		class HttpServer;

		class Session : public std::enable_shared_from_this<Session>
		{
		public:
			Session(boost::asio::io_context& io_context) noexcept;
			~Session() noexcept;

			void start();

		private:
			void doRead();
			void doSend();

			boost::asio::io_context& io_context_;
			boost::asio::ip::tcp::socket socket_;

			hc::network::Request client_request_;
			char data_[hc::settings::BUFFER_SIZE];

			friend HttpServer;
		};
	}
}