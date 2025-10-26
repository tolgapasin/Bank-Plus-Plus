cmake_minimum_required(VERSION 3.14)
project("Bank++")

add_executable(Bank++ src/main.cpp src/banking_console.cpp src/bank_account.cpp src/helpers/console_helper.cpp src/helpers/dollar_cent_conversion_helper.cpp)

# TODO: figure out how to reference entire src & test directories instead of specific files
# Add source files
#add_subdirectory(src)
#add_executable(my_app src/main.cpp)

# Enable testing and add GoogleTest-based tests
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Define test executable(s)
add_executable(bank_tests
    test/helpers/test_dollar_cent_conversion.cpp
    src/helpers/dollar_cent_conversion_helper.cpp
    test/test_bank_account.cpp
    src/bank_account.cpp
)
target_include_directories(bank_tests PRIVATE ${CMAKE_SOURCE_DIR})

# Link with gtest_main
target_link_libraries(bank_tests PRIVATE gtest_main)

# Discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(bank_tests)