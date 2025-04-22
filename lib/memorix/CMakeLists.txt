add_library(memorix STATIC app.cpp card_deck.cpp)

target_include_directories(memorix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
