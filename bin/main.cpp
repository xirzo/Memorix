#include <cstdlib>

#include "app.h"

int main(void) {
    memorix::App app;

    while (app.IsRunning()) {
        app.Update();
    }

    return EXIT_SUCCESS;
}
