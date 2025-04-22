add_library(memorix STATIC memorix.cpp)

target_include_directories(memorix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
