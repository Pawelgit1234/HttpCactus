#include <boost/asio.hpp>

#include "network/HttpServer.hpp"

int main(int argc, char* argv[])
{
	hc::network::HttpServer server;
	server.addStaticFolderPath("static/");
	server.addFile("html/index.html", "/");
	server.run();

	return 0;
}