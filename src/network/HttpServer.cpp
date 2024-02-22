#include "HttpServer.hpp"

using boost::asio::ip::tcp;

namespace hc
{
	namespace network
	{
		HttpServer::HttpServer() noexcept : acceptor_(io_context_, tcp::endpoint(tcp::v4(), hc::settings::PORT)), request_handler_(router_, static_file_manager_)
		{
		}

		HttpServer::~HttpServer() noexcept
		{
		}

		void HttpServer::run()
		{
			startAccept();
		}

		void HttpServer::addStaticFolderPath(const std::string& path)
		{
			static_file_manager_.setStaticFolderPath(path);
		}

		void HttpServer::addText(const std::string& text, const std::string& url)
		{
		}

		void HttpServer::addFile(const std::string& path, const std::string& url)
		{
			router_.addUrl(url, path);
			static_file_manager_.addStaticFile(path);
		}

		void HttpServer::startAccept()
		{
			hc::logger::log("Server started accepting.", hc::logger::LoggerType::INFO);

			while (true)
			{
				auto session = std::make_shared<Session>(io_context_, request_handler_);
				acceptor_.accept(session->socket_);

				std::thread([session]()
					{
						session->start();
					}).detach();
			}
		}
	}
}