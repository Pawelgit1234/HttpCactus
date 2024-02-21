#include "HttpServer.hpp"

using boost::asio::ip::tcp;

namespace hc
{
	namespace network
	{
		HttpServer::HttpServer() noexcept : acceptor_(io_context_, tcp::endpoint(tcp::v4(), hc::settings::PORT)) {}

		HttpServer::~HttpServer() noexcept
		{
		}

		void HttpServer::run()
		{
			startAccept();
		}

		void HttpServer::addText(const std::string& text, const std::string& url)
		{
		}

		void HttpServer::addFile(const std::string& path, const std::string& url)
		{
		}

		void HttpServer::startAccept()
		{
			hc::logger::log("Server started accepting.", hc::logger::LoggerType::INFO);

			while (true)
			{
				auto session = std::make_shared<Session>(io_context_);
				acceptor_.accept(session->socket_);

				std::thread([session]()
					{
						session->start();
					}).detach();
			}
		}
	}
}