#ifndef IO_H
#define IO_H

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

    virtual bool hasInput() const = 0;
    virtual InputType getInput() const = 0;
    virtual void output(std::string_view text) const = 0;
};
}  // namespace memorix

#endif  // !IO_H
