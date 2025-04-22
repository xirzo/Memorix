#ifndef IO_H
#define IO_H

namespace memorix {
class IO
{
public:
    virtual bool waitInput() const = 0;
    virtual ~IO() = default;
};
}  // namespace memorix

#endif  // !IO_H
