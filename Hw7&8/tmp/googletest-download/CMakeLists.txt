cmake_minimum_required(VERSION 3.10)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "/Users/bradybodily/Repositories/CS3460/Hw7&8/tmp/googletest-src"
  BINARY_DIR        "/Users/bradybodily/Repositories/CS3460/Hw7&8/tmp/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
