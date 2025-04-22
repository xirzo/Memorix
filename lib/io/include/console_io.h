#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include "io.h"

namespace io {

class Console : public memorix::IO
{
public:
    bool hasInput() const override;
    memorix::InputType getInput() const override;
};

};  // namespace io

#endif  // !CONSOLE_IO_H
