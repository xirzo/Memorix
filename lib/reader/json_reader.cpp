#include "json_reader.h"

#include <utility>

namespace reader {

Json::Json(std::filesystem::path filename) : filename_(std::move(filename)) {}

std::vector<memorix::Card> Json::tryRead() const {
    return {};
};

};  // namespace reader
