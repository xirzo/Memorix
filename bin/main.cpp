#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

#include "app.h"
#include "json_reader.h"

int main(void) {
    auto json_reader = std::make_unique<reader::Json>("cards.json");

    memorix::App app(std::move(json_reader));

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
