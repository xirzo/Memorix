#ifndef APP_H
#define APP_H

#include <memory>

#include "file_reader.h"

namespace memorix {

class App
{
public:
    explicit App(std::unique_ptr<FileReader> file_reader);

    bool isRunning() const;
    void update();

private:
    bool is_running_;
    std::unique_ptr<FileReader> file_reader_;
    std::vector<Card> cards_;
};

}  // namespace memorix
#endif  // !APP_H
