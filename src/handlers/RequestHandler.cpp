#include "RequestHandler.hpp"

namespace hc
{
	namespace handler
	{
		RequestHandler::RequestHandler(hc::network::Router& router, hc::manager::StaticFileManager& static_file_manager) noexcept
			: router_(router), static_file_manager_(static_file_manager)
		{
		}

		RequestHandler::~RequestHandler() noexcept
		{
		}

		std::string RequestHandler::handleRequest(hc::network::Request& request)
		{
			hc::network::Request answer;
			std::string body = static_file_manager_.getStaticFileContent(router_.getPath(request.getURL()));

			if (body.size() == 0)
			{
				answer.setContentType(request.getContentType());
				answer.setRequestStatus(hc::network::RequestStatus::SERVER_ERROR_404);
				return answer.getRawRequest("<h1>Page not found!</h1>");
			}

			answer.setContentType(request.getContentType());
			answer.setRequestStatus(hc::network::RequestStatus::OK_200);
			return answer.getRawRequest(body);
		}
	}
}