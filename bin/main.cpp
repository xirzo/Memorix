#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

#include "app.h"
#include "json_reader.h"
#include "server.h"

int main(void) {
    try {
        auto json_reader = std::make_unique<reader::Json>("cards.json");
        auto console_io = std::make_unique<io::Server>();

        memorix::App app(std::move(json_reader), std::move(console_io));

        app.run();

        std::cout << "Press any key to quit." << std::endl;

        std::cin.get();
        app.stop();

        return EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
