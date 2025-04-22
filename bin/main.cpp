#include <cstdlib>
#include <memory>

#include "app.h"
#include "json_reader.h"

int main(void) {
    memorix::App app(std::make_unique<reader::Json>("cards.json"));

    while (app.isRunning()) {
        app.update();
    }

    return EXIT_SUCCESS;
}
