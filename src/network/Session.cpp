#include "Session.hpp"

using boost::asio::ip::tcp;

namespace hc
{
	namespace network
	{
		Session::Session(boost::asio::io_context& io_context, hc::network::Router& router, hc::handler::RequestHandler& request_handler, hc::manager::StaticFileManager& static_file_manager) noexcept
			: io_context_(io_context), socket_(io_context), router_(router), request_handler_(request_handler), static_file_manager_(static_file_manager)
		{
		}

		Session::~Session() noexcept
		{
		}

		void Session::start()
		{
			hc::logger::log("Client accepted.", hc::logger::LoggerType::INFO);
			doRead();
			doSend();
			socket_.close();
		}

		void Session::doRead()
		{
			socket_.read_some(boost::asio::buffer(data_, hc::settings::BUFFER_SIZE));
			Request request;
			request.parseRawRequest(std::string(data_));
		}

		void Session::doSend()
		{
			hc::network::Request server_requst;
			socket_.write_some(boost::asio::buffer(data_, hc::settings::BUFFER_SIZE));
		}
	}
}