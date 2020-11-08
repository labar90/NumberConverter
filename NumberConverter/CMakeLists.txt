cmake_minimum_required (VERSION 3.8)
project (NumberConverter)

set(CMAKE_CXX_STANDARD 14)

include_directories("src")

add_subdirectory ("application")
add_subdirectory ("test")
