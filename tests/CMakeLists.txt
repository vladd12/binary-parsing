option(BINPARSING_LIBCURL_TESTS "Run tests with libcurl binaries" ON)

set(BINPARSING_TESTS_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/simple_test.cpp
)

add_executable(binary_parsing_tests ${BINPARSING_TESTS_SOURCES})
target_link_libraries(binary_parsing_tests PUBLIC
  GTest::GTest
  binary::parsing
)

add_test(
  NAME binary_parsing_tests
  COMMAND binary_parsing_tests
)

if(BINPARSING_LIBCURL_TESTS)
  add_subdirectory(cli)
  add_subdirectory(curl_tests)
  add_test(
    NAME binary_parsing_curl_so_tests
    COMMAND binary_parsing_curl_tests --file ${CMAKE_CURRENT_BINARY_DIR}/libcurl-gnutls.so.4.8.0
  )
  add_test(
    NAME binary_parsing_curl_exe_tests
    COMMAND binary_parsing_curl_tests -- file ${CMAKE_CURRENT_BINARY_DIR}/curl-amd64
  )
endif()
