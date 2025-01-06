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

# Create the executable
add_executable(eliptic ${SOURCES})

# Include directories
target_include_directories(eliptic PRIVATE include)

# Ensure C++11 features are available
target_compile_features(eliptic PRIVATE cxx_std_11)

# Enable testing
include(CTest)
enable_testing()

# Fetch and include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

# Link GoogleTest libraries
target_link_libraries(eliptic gtest gtest_main)

# Add a test
add_test(NAME UnityTests COMMAND unity-test)

# Installation rules
install(TARGETS eliptic DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Debug" FORCE)
endif()
