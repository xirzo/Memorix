#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

#include "app.h"
#include "console_io.h"
#include "json_reader.h"

int main(void) {
    auto json_reader = std::make_unique<reader::Json>("cards.json");
    auto console_io = std::make_unique<io::Console>();

    memorix::App app(std::move(json_reader), std::move(console_io));

    while (app.isRunning()) {
        try {
            app.update();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
