#include "console_io.h"

#include <algorithm>
#include <cctype>
#include <iostream>

#include "io.h"

namespace io {

// bool Console::hasInput() const {
//     return std::cin.peek() != std::char_traits<char>::eof();
// }
//
// memorix::InputType Console::getInput() const {
//     std::string i;
//
//     if (!std::getline(std::cin, i)) {
//         return memorix::InputType::UNKNOWN;
//     }
//
//     auto tolower = static_cast<int (*)(int)>(std::tolower);
//
//     std::transform(i.begin(), i.end(), i.begin(),
//                    [=](unsigned char c) { return static_cast<char>(tolower(c)); });
//     if (i == "n") {
//         return memorix::InputType::NEXT_CARD;
//     } else if (i == "p") {
//         return memorix::InputType::PREVIOUS_CARD;
//     } else if (i == "f") {
//         return memorix::InputType::FLIP_CARD;
//     } else if (i == "q") {
//         return memorix::InputType::QUIT;
//     }
//     return memorix::InputType::UNKNOWN;
// }
//
// void Console::output(std::string_view text) const {
//     std::cout << text << std::endl;
// }

}  // namespace io
