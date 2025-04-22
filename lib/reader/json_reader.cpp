#include "json_reader.h"

#include <filesystem>
#include <stdexcept>
#include <utility>

namespace reader {

Json::Json(std::filesystem::path filename) : filename_(std::move(filename)) {}

std::vector<memorix::Card> Json::tryRead() const {
    if (std::filesystem::exists(filename_) == false) {
        throw std::invalid_argument("File " + filename_.string() + " does not exist");
    }

    // also throw if cards empty

    return {};
};

};  // namespace reader
