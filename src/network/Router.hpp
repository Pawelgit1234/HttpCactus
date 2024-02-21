#pragma once

#include <vector>

#include "../managers/StaticFileManager.hpp"

namespace hc
{
	namespace network
	{
		class Router
		{
		public:
			Router() noexcept;
			~Router() noexcept;

		private:
			hc::manager::StaticFileManager static_file_manager_;
		};
	}
}