#ifndef JSON_READER_H
#define JSON_READER_H

#include <filesystem>

#include "file_reader.h"

namespace reader {

class Json : public memorix::FileReader
{
public:
    explicit Json(std::filesystem::path filename);

    std::vector<memorix::Card> tryRead() const override;

private:
    const std::filesystem::path filename_;
};

};  // namespace reader

#endif  // !JSON_READER_H
