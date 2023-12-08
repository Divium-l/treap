//
// Created by Divium on 02.10.2023.
//

#pragma once

namespace mit {

    template<typename T>
    struct Node {
        T value, priority;
        Node *left, *right, *parent;
        Node(): left(nullptr), right(nullptr), parent(nullptr) {}
    };

}

