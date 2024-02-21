#include "Session.hpp"

using boost::asio::ip::tcp;

namespace hc
{
	namespace network
	{
		Session::Session(boost::asio::io_context& io_context) noexcept
			: io_context_(io_context), socket_(io_context)
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
			request_.parseRawRequest(std::string(data_));
			
			std::cout << "Request Method: " << int(request_.getRequestMethod()) << std::endl;
			std::cout << "Request URL: " << request_.getURL() << std::endl;
			std::cout << "Request User Agent: " << request_.getUserAgent() << std::endl;
			std::cout << "Request Host: " << request_.getHost() << std::endl;
			std::cout << "Request Content Type: " << int(request_.getContentType()) << std::endl;
		}

		void Session::doSend()
		{
			socket_.write_some(boost::asio::buffer(data_, hc::settings::BUFFER_SIZE));
		}
	}
}