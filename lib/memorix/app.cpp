#include "app.h"

namespace memorix {

App::App() : is_running_(false) {}

bool App::IsRunning() const {
    return is_running_;
}

void App::Update() {}

}  // namespace memorix
