cmake_minimum_required(VERSION 3.5.0)
project(eliptic VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cc")
file(GLOB_RECURSE INCLUDES "include/*.hpp")

add_executable(eliptic ${SOURCES})

target_include_directories(eliptic PRIVATE include)
target_compile_features(eliptic PRIVATE cxx_std_11)

include(CTest)
enable_testing()

install(TARGETS eliptic DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
