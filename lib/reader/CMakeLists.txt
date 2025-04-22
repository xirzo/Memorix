add_library(reader STATIC json_reader.cpp)

target_link_libraries(reader PUBLIC memorix)

target_include_directories(reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
