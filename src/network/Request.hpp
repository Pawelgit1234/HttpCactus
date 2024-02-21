#pragma once

#include <boost\asio.hpp>

#include <memory>
#include <string>
#include <regex>

namespace hc
{
	namespace network
	{
		enum class RequestMethod
		{
			GET,
			POST,
		};

		enum class RequestContentType
		{
			HTML,
			JSON,
			XML,
			PLAIN_TEXT,
			BINARY,
		};

		class Request : public std::enable_shared_from_this<Request>
		{
		public:
			void parseRawRequest(const std::string& request);

			RequestMethod getRequestMethod() const { return method_; }
			const std::string& getBody() const { return body_; }
			const std::string& getHeader() const { return header_; }
			const std::string& getURL() const { return url_; }
			const std::string& getUserAgent() const { return user_agent_; }
			const std::string& getHost() const { return host_; }
			RequestContentType getContentType() const { return content_type_; }

		private:
			RequestMethod method_;
			RequestContentType content_type_;
			std::string url_;
			std::string user_agent_;
			std::string host_;

			std::string header_;
			std::string body_;
		};
	}
}