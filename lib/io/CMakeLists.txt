add_library(io STATIC console_io.cpp server.cpp)

target_link_libraries(io PUBLIC Crow::Crow memorix)

target_include_directories(io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
