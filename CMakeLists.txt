set(PROJECT_NAME "Treap")
set(EXECUTABLE_NAME "treap")

cmake_minimum_required(VERSION 3.26)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_subdirectory(src)
add_subdirectory(test)