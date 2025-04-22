#ifndef IO_H
#define IO_H

#include <functional>
#include <string_view>

namespace memorix {

enum class InputType
{
    UNKNOWN,
    NEXT_CARD,
    PREVIOUS_CARD,
    FLIP_CARD,
    QUIT,
};

class IO
{
public:
    virtual ~IO() = default;

    virtual void setInputCallback(std::function<void(InputType)> callback) = 0;
    virtual void startListening() = 0;
    virtual void stopListening() = 0;

    virtual void output(std::string_view text) const = 0;
};
}  // namespace memorix

#endif  // !IO_H
