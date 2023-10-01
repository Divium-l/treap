//
// Created by Egor-Always-AFK on 26.09.2023.
//

#include "Node.h"

namespace mit {
    template<class T>
    Node<T>::Node(T key, int priority, Node *left, Node *right) {
        this->key = key;
        this->priority = priority;
        this->left = left;
        this->right = right;
    }

    template<class T>
    Node<T>::~Node() {
        key = nullptr;
        priority = 0;
        free(left);
        free(right);
    }

    template<class T>
    void Node<T>::split() {

    }

    template<class T>
    void Node<T>::merge() {

    }

    template<class T>
    void Node<T>::insert() {

    }

    template<class T>
    void Node<T>::erase() {

    }

} // mit