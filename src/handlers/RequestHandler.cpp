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
			answer.setContentType(request.getContentType());
			answer.setRequestStatus(hc::network::RequestStatus::OK_200);
			std::string body = static_file_manager_.getStaticFileContent(router_.getPath(request.getURL()));
			return answer.getRawRequest(body);
		}
	}
}