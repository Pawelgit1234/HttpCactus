#include "Session.hpp"

using boost::asio::ip::tcp;

namespace hc
{
	namespace network
	{
		Session::Session(boost::asio::io_context& io_context, hc::handler::RequestHandler& request_handler) noexcept
			: io_context_(io_context), socket_(io_context), request_handler_(request_handler)
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
			client_request_.parseRawRequest(std::string(data_));
			hc::logger::log("Got a request.", hc::logger::LoggerType::INFO);
		}

		void Session::doSend()
		{
			std::string request = request_handler_.handleRequest(client_request_);
			socket_.write_some(boost::asio::buffer(request));
			hc::logger::log("Sent a answer.", hc::logger::LoggerType::INFO);
		}
	}
}