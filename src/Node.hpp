//
// Created by Divium on 02.10.2023.
//

#pragma once

#include <random>
#include <memory>

namespace mit {
    template<typename T>
    struct Node {
        T value;
        int priority;
        std::shared_ptr<Node<T>> left, right, parent;

        explicit Node():
                left(nullptr), right(nullptr), parent(nullptr), value(0), priority(randomInt()) {}

        explicit Node(T value):
                left(nullptr), right(nullptr), parent(nullptr), value(value), priority(randomInt()) {}

        explicit Node(T value, int priority):
                left(nullptr), right(nullptr), parent(nullptr), value(value), priority(priority) {}

    protected:
        static int randomInt() {
            auto randomDevice = std::random_device();
            auto mt = std::mt19937(randomDevice());
            auto distribution = std::uniform_int_distribution<int>();

            return distribution(mt);
        }
    };
}

