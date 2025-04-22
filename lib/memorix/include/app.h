#ifndef APP_H
#define APP_H

#include <memory>

#include "file_reader.h"
#include "io.h"

namespace memorix {

class App
{
public:
    App(std::unique_ptr<FileReader> file_reader, std::unique_ptr<IO> io);

    bool isRunning() const;
    void update();

private:
    bool is_running_;
    std::unique_ptr<FileReader> file_reader_;
    std::unique_ptr<IO> io_;
    std::vector<Card> cards_;
};

}  // namespace memorix
#endif  // !APP_H
