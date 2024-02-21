#include "request.hpp"


namespace hc
{
    namespace network
    {
        void Request::parseRawRequest(const std::string& request)
        {
            std::regex method_regex("^(GET|POST)\\s");
            std::regex url_regex("^(GET|POST)\\s(\\S+)\\s");
            std::regex user_agent_regex("User-Agent:\\s*([^\\r\\n]+)");
            std::regex host_regex("Host:\\s*([^\\r\\n]+)");
            std::regex accept_regex("Accept:\\s*([^\\r\\n]+)");
            std::smatch match;

            if (std::regex_search(request, match, method_regex))
            {
                std::string method_str = match[1];
                if (method_str == "GET")
                    method_ = RequestMethod::GET;
                else if (method_str == "POST")
                    method_ = RequestMethod::POST;
            }

            if (std::regex_search(request, match, url_regex))
                url_ = match[2];

            if (std::regex_search(request, match, user_agent_regex))
                user_agent_ = match[1];

            if (std::regex_search(request, match, host_regex))
                host_ = match[1];

            if (std::regex_search(request, match, accept_regex))
            {
                std::string accept_str = match[1];
                if (accept_str.find("text/html") != std::string::npos)
                    content_type_ = RequestContentType::HTML;
                else if (accept_str.find("application/json") != std::string::npos)
                    content_type_ = RequestContentType::JSON;
                else if (accept_str.find("application/xml") != std::string::npos)
                    content_type_ = RequestContentType::XML;
                else if (accept_str.find("text/plain") != std::string::npos)
                    content_type_ = RequestContentType::PLAIN_TEXT;
                else
                    content_type_ = RequestContentType::BINARY;
            }
        }
        std::string Request::getRawRequest(hc::network::RequestStatus status, hc::network::RequestContentType type, const std::string& body)
        {
            std::string status_line;
            switch (status)
            {
            case RequestStatus::OK_200:
                status_line = "HTTP/1.1 200 OK";
                break;
            case RequestStatus::SERVER_ERROR_404:
                status_line = "HTTP/1.1 404 Not Found";
                break;
            }

            std::string content_type;
            switch (type)
            {
            case RequestContentType::HTML:
                content_type = "text/html";
                break;
            case RequestContentType::JSON:
                content_type = "application/json";
                break;
            case RequestContentType::XML:
                content_type = "application/xml";
                break;
            case RequestContentType::PLAIN_TEXT:
                content_type = "text/plain";
                break;
            case RequestContentType::BINARY:
                content_type = "application/octet-stream";
                break;
            }

            std::string header = status_line + "\r\n";
            header += "Content-Type: " + content_type + "\r\n";
            header += "Content-Length: " + std::to_string(body.length()) + "\r\n";
            header += "\r\n";

            return header + body;
        }
    }
}
