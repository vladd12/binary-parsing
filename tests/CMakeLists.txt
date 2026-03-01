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

# Downloading libcurl executable file
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/curl-amd64")
  message(STATUS "Downloading curl-amd64 from https://github.com/moparisthebest/static-curl")
  file(
    DOWNLOAD "https://github.com/moparisthebest/static-curl/releases/download/v8.17.0/curl-amd64" "${CMAKE_CURRENT_BINARY_DIR}/curl-amd64"
    EXPECTED_HASH SHA256=b01914a4cbd8497d8550010c2d27d2030614d532aaca60e89a3929a734c451b5
    TLS_VERIFY ON
  )
endif()

# Downloading libcurl executable file
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/libcurl3t64-amd64.deb")
  message(STATUS "Downloading libcurl3t64 debian package from http://ftp.us.debian.org")
  file(
    DOWNLOAD "http://ftp.us.debian.org/debian/pool/main/c/curl/libcurl3t64-gnutls_8.14.1-2+deb13u2_amd64.deb" "${CMAKE_CURRENT_BINARY_DIR}/libcurl3t64-amd64.deb"
    EXPECTED_HASH SHA256=bcdd5e493550af6a1e9dedabeddea8270cdbbb69f726038ef805b731a8b957d4
    TLS_VERIFY ON
  )
endif()

