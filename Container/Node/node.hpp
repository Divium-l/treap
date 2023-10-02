//
// Created by Divium on 02.10.2023.
//

#pragma once

namespace mit {

    template <class T> class Node {

    public:
        explicit Node() = default;
        explicit Node(T key) : key(key) {}
        explicit Node(T key, int priority, Node *left, Node *right) : key(key), priority(priority), left(left), right(right) {};
        ~Node();

    private:
        T key;
        int priority;
        Node* left;
        Node* right;
    };

    template<class T> Node<T>::~Node() {
        delete right;
        delete left;
    }

}

