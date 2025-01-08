cmake_minimum_required(VERSION 3.5.0)
project(eliptic VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Collect source and header files
file(GLOB_RECURSE SOURCES "src/*.cc")
file(GLOB_RECURSE INCLUDES "include/*.hpp")

# Create a static library instead of an executable for shared code
add_library(eliptic-lib STATIC ${SOURCES})

# Include directories
target_include_directories(eliptic-lib PUBLIC include)

# Ensure C++17 features are available
target_compile_features(eliptic-lib PRIVATE cxx_std_17)

# Create the executable for the project (if you still want it)
add_executable(eliptic src/main.cc)  

# Link the static library to your executable
target_link_libraries(eliptic PRIVATE eliptic-lib)

# Testing configuration
enable_testing()

# Add test sources
file(GLOB TEST_SOURCES "tests/*.cc")

# Create a test executable
add_executable(unit-test ${TEST_SOURCES})

# Link GoogleTest libraries and the static library
target_link_libraries(unit-test PRIVATE gtest gtest_main eliptic-lib)

# Include directories for tests
target_include_directories(unit-test PRIVATE include)

# Add tests
add_test(NAME UnitTests COMMAND unit-test)

# Installation rules
install(TARGETS eliptic DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Debug" FORCE)
endif()
