add_library(io STATIC console_io.cpp)

target_link_libraries(io PUBLIC memorix)

target_include_directories(io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
