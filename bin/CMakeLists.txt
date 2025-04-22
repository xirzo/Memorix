add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE memorix
          reader
          io
          Threads::Threads
          ZLIB::ZLIB
          OpenSSL::SSL
          OpenSSL::Crypto)
