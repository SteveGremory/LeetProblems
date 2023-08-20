cmake_minimum_required(VERSION 3.22)
project(FacebookProblems)

# Set C++ options
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GTest
set(GTEST_GIT_TAG v1.13.0)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG ${GTEST_GIT_TAG}
        )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
message("-- Fetched GTest version: ${GTEST_GIT_TAG}")

# cppcheck
find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
        message("-- cppcheck found!")
        list(
                APPEND CMAKE_CXX_CPPCHECK
                "--enable=warning"
                "--inconclusive"
                "--force"
                "--inline-suppr"
        )
else()
        message(FATAL_ERROR "-- Failed to find cppcheck binary. Please add it to path/install it.")
endif()

# Get all C++ files
file(GLOB_RECURSE ANSWERS_SOURCES
        source/*.cc
)

# Add the testlib
add_library(libAnswers ${ANSWERS_SOURCES})

# Get all test files
file(GLOB_RECURSE TESTS_SOURCES
        tests/*.cc
)

# Tests
add_executable(Tests ${TESTS_SOURCES})
target_include_directories(Tests PUBLIC
        source/
)

target_link_libraries(Tests
        GTest::gtest_main
        libAnswers
)

include(GoogleTest)
gtest_discover_tests(Tests)

