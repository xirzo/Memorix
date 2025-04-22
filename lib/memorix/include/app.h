#ifndef APP_H
#define APP_H

#include <memory>

#include "card_deck.h"
#include "file_reader.h"
#include "io.h"

namespace memorix {

class App
{
public:
    App(std::unique_ptr<FileReader> file_reader, std::unique_ptr<IO> io);
    ~App();

    bool isRunning() const;
    void run();
    void stop();

private:
    void updateDisplay();
    void handleInput(InputType input);

private:
    bool is_running_;
    std::unique_ptr<FileReader> file_reader_;
    std::unique_ptr<IO> io_;
    std::unique_ptr<CardDeck> deck_;
};

}  // namespace memorix
#endif  // !APP_H
