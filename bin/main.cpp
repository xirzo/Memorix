#include <cstdlib>

#include "memorix.h"

int main(void) {
    Memorix app;

    while (app.IsRunning()) {
        app.Update();
    }

    return EXIT_SUCCESS;
}
