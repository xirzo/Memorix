add_library(memorix STATIC app.cpp)

target_include_directories(memorix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
