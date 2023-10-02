cmake_minimum_required(VERSION 3.26)
project(treap)

set(CMAKE_CXX_STANDARD 23)

include_directories(Container)
include_directories(Iterator)

add_executable(treap
        main.cpp
        Container/Node/Node.cc
        Container/Node/Node.h
        Container/Node/node.hpp)
