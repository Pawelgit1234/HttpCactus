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

		enum class RequestStatus
		{
			OK_200,
			SERVER_ERROR_404,
		};

		class Request : public std::enable_shared_from_this<Request>
		{
		public:
			void parseRawRequest(const std::string& request);
			std::string getRawRequest(hc::network::RequestStatus status, hc::network::RequestContentType type, const std::string& body);

			RequestMethod getRequestMethod() const { return method_; }
			RequestContentType getContentType() const { return content_type_; }
			const std::string& getBody() const { return body_; }
			const std::string& getHeader() const { return header_; }
			const std::string& getURL() const { return url_; }
			const std::string& getUserAgent() const { return user_agent_; }
			const std::string& getHost() const { return host_; }

			void setRequestMethod(hc::network::RequestMethod method) { method_ = method; }
			void setContentType(hc::network::RequestContentType content_type) { content_type_ = content_type; }
			void setBody(const std::string& body) { body_; }
			void setHeader(const std::string& header) { header_ = header; }
			void setURL(const std::string& url) { url_ = url; }
			void setUserAgent(const std::string& user_agent) { user_agent_ = user_agent; }
			void setHost(const std::string& host) { host_ = host; }

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