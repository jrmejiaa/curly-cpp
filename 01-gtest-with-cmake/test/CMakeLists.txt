include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(multiply_test multiply_test.cpp)

target_link_libraries(multiply_test
  PRIVATE
  GTest::GTest
  multiply
)

add_test(multiply_gtests multiply_test)

add_test(NAME script_test
  COMMAND "${CMAKE_CURRENT_LIST_DIR}/script_test.sh"
  WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
)
