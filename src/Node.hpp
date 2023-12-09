//
// Created by Divium on 02.10.2023.
//

#pragma once

#include <random>

namespace mit {

    template<typename T>
    struct Node {
        T value;
        int priority;
        Node *left, *right, *parent;

        explicit Node():
                left(nullptr), right(nullptr), parent(nullptr), value(0), priority(rand()) {}

        explicit Node(T value):
                left(nullptr), right(nullptr), parent(nullptr), value(value), priority(rand()) { };

        explicit Node(T value, int priority):
                left(nullptr), right(nullptr), parent(nullptr), value(value), priority(priority) {  }
    };
}

