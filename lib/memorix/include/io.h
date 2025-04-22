#ifndef IO_H
#define IO_H

namespace memorix {
enum class InputType
{
    EMPTY,
    UNKNOWN,
    NEXT_CARD,
    PREVIOUS_CARD,
};

class IO
{
public:
    virtual ~IO() = default;

    virtual bool hasInput() const = 0;
    virtual InputType getInput() const = 0;
};
}  // namespace memorix

#endif  // !IO_H
