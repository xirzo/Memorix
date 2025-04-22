#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>

#include "card.h"

namespace memorix {

class FileReader
{
public:
    virtual std::vector<Card> tryRead() const = 0;
    virtual ~FileReader() = default;
};

}  // namespace memorix

#endif  // !FILE_READER_H
