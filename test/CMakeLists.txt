cmake_minimum_required(VERSION 3.20)
project(treap)

set(CMAKE_CXX_STANDARD 23)

enable_testing()
add_executable(treapTest
        DecartTreeTest.cc
        NodeTest.cc)
target_link_libraries(treapTest gtest gmock)
