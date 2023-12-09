//
// Created by Egor-Always-AFK on 01.10.2023.
//

#ifndef HEAP_DECARTTREE_H
#define HEAP_DECARTTREE_H

#include "Node.hpp"
#include <utility>

namespace mit {

    template<typename T>
    class DecartTree {
    private:
        mit::Node<T> *root;

        bool contains(T value, mit::Node<T> node) {
            if (node == nullptr) {
                return false;
            } else if (node.value == value) {
                return true;
            } else if (node.value >= value) {
                find(node.left);
            } else {
                find(node.right);
            }
        }

        mit::Node<T> *merge(Node<int> *leftNode, mit::Node<T> *rightNode) {
            if (!leftNode) {
                return rightNode;
            } else if (!rightNode) {
                return leftNode;
            } else {
                if (leftNode->priority > rightNode->priority) {
                    leftNode->right = merge(leftNode->right, rightNode);
                    return leftNode;
                } else {
                    rightNode->left = merge(leftNode, rightNode->left);
                    return rightNode;
                }
            }
        }

        std::pair<mit::Node<T> *, mit::Node<T> *> split(mit::Node<T> *node, int keyForSplit) {
            if (!node) {
                return {nullptr, nullptr};
            } else {
                if (node->value <= keyForSplit) {
                    auto [left, right] = split(node->right, keyForSplit);
                    node->right = left;
                    return {node, right};
                } else {
                    auto [left, right] = split(node->left, keyForSplit);
                    node->left = right;
                    return {left, right};
                }
            }
        }

    public:
        DecartTree() : root(nullptr) {}
        ~DecartTree() {
            delete root;
        }

        void merge(mit::DecartTree<T> treeForMerge) {
            this->root = merge(this->root, treeForMerge.root);
        }

        std::pair<mit::Node<T> *, mit::Node<T> *> split(int keyForSplit) {
            auto [leftTree, rightTree] = split(this->root, keyForSplit);
            this->root = leftTree;
            return {leftTree, rightTree};
        }

        void add(T value) {
            auto [leftTree, rightTree] = split(this->root, value);
            mit::Node<int> *newNode = new mit::Node<T>(value);
            this->root = merge(leftTree, merge(newNode, rightTree));
        }

        void add(T value, int priority) {
            auto [leftTree, rightTree] = split(this->root, value);
            mit::Node<int> *newNode = new mit::Node<T>(value, priority);
            this->root = merge(leftTree, merge(newNode, rightTree));
        }

        void addAll(T *value) {
            for (auto data: value) {
                this->add(data);
            }
        }

        bool contains(T value) {
            return contains(value);
        }

        void clear() {
            delete this->root;
        }

        mit::Node<T> *getRoot() {
            return root;
        }
    };

} // mit

#endif //HEAP_DECARTTREE_H
