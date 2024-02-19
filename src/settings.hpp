#pragma once

#define ENABLE_LOGGER

#ifdef ENABLE_LOGGER
#define WRITE_IN_FILE
#define ADD_TIME
#endif // ENABLE_LOGGER

namespace hc
{
	namespace settings
	{
		const unsigned short PORT = 8080;
	}
}