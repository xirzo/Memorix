#include "json_reader.h"

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <utility>

#include "card.h"

namespace reader {

Json::Json(std::filesystem::path filename) : filename_(std::move(filename)) {}

std::vector<memorix::Card> Json::tryRead() const {
    if (std::filesystem::exists(filename_) == false) {
        throw std::invalid_argument("File " + filename_.string() + " does not exist");
    }

    std::ifstream file(filename_);

    if (file.is_open() == false) {
        throw std::invalid_argument("File " + filename_.string() + " cannot be openned");
    }

    nlohmann::json j = nlohmann::json::parse(file);

    std::vector<memorix::Card> cards;

    for (nlohmann::json &el : j) {
        cards.emplace_back(el["front"].get<std::string>(), el["back"].get<std::string>());
    }

    if (cards.empty()) {
        throw std::invalid_argument("No cards in file " + filename_.string());
    }

    return cards;
};

};  // namespace reader
