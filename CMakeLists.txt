cmake_minimum_required(VERSION 3.26)
project(heap)

set(CMAKE_CXX_STANDARD 14)

include_directories(Container)
include_directories(Iterator)

add_executable(heap
        Container/Heap.cpp
        Container/Heap.h
        Iterator/HeapIterator.cpp
        Iterator/HeapIterator.h)
