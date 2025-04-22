#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include "io.h"

namespace io {

class Console : public memorix::IO
{
public:
    Console();

    bool waitInput() const override;

private:
};

};  // namespace io

#endif  // !CONSOLE_IO_H
