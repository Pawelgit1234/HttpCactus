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
			client_request_.parseRawRequest(std::string(data_));
		}

		void Session::doSend()
		{
			hc::network::Request server_requst;
			std::string raw_reuqest = server_requst.getRawRequest(hc::network::RequestStatus::OK_200, hc::network::RequestContentType::HTML, "<h1>Hello World</h1>");
			socket_.write_some(boost::asio::buffer(raw_reuqest));
		}
	}
}