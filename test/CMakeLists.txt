cmake_minimum_required(VERSION 3.20)
project(treap)

set(CMAKE_CXX_STANDARD 23)

include_directories(Container)
include_directories(Iterator)

add_executable(treap NodeTest.cc
                DecartTreeTest.cc)
