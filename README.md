![HttpCactus](img/cactus.png)
# HttpCactus
HttpCactus is a lightweight and efficient web server implemented in C++. It provides essential functionalities for serving web content with minimal overhead, making it perfect for small to medium-scale applications. With its minimalistic design, HttpCactus prioritizes simplicity and performance, offering a straightforward solution for handling concurrent connections and serving HTTP requests.

## Installation

Use the git clone command to install the code.

```bash
git clone https://github.com/Pawelgit1234/HttpCactus.git
```

## Usage
To use HttpCactus in your C++ project, follow these steps:

1. Include the HttpServer.hpp header file in your main source file.
2. Create an instance of the HttpServer class.
3. Add any necessary configurations, such as static folder paths or specific file mappings.
4. Call the run() method on the server instance to start the server.

```c
#include "network/HttpServer.hpp"

int main(int argc, char* argv[])
{
	hc::network::HttpServer server;
	server.addStaticFolderPath("static/");
	server.addFile("html/index.html", "/");
	server.run();

	return 0;
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
