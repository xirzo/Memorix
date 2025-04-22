add_library(reader STATIC json_reader.cpp)

target_link_libraries(
  reader
  PRIVATE nlohmann_json::nlohmann_json
  PUBLIC memorix)

target_include_directories(reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
