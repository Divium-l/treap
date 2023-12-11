//
// Created by Egor-Always-AFK on 01.10.2023.
//

#ifndef HEAP_DECARTTREE_H
#define HEAP_DECARTTREE_H

#include "Node.hpp"
#include <utility>
#include <memory>

namespace mit {

    template<typename T>
    class DecartTree {
    private:
        typedef std::shared_ptr<mit::Node<T>> Node;

        Node root;

        bool contains(T value, Node node) {
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

        std::shared_ptr<mit::Node<T>> merge(Node leftNode, Node rightNode) {
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

        std::pair<Node, Node> _split(Node node, int keyForSplit) {
            if (!node) {
                return {nullptr, nullptr};
            } else {
                if (node->value <= keyForSplit) {
                    auto [left, right] = _split(node->right, keyForSplit);
                    node->right = left;
                    return {node, right};
                } else {
                    auto [left, right] = _split(node->left, keyForSplit);
                    node->left = right;
                    return {left, node};
                }
            }
        }

    public:
        DecartTree() : root(nullptr) {}
        ~DecartTree() = default;

        void merge(mit::DecartTree<T> treeForMerge) {
            this->root = merge(this->root, treeForMerge.root);
        }

        std::pair<Node, Node> split(int keyForSplit) {
            auto [leftTree, rightTree] = _split(this->root, keyForSplit);
            this->root = leftTree;
            return {leftTree, rightTree};
        }

        void add(T value) {
            auto [leftTree, rightTree] = _split(this->root, value);
            auto newNode = Node(new mit::Node(value));

            this->root = merge(leftTree, merge(newNode, rightTree));
        }

        void add(T value, int priority) {
            auto [leftTree, rightTree] = _split(this->root, value);
            Node newNode = Node(new mit::Node(value, priority));
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

        Node getRoot() {
            return root;
        }
    };

} // mit

#endif //HEAP_DECARTTREE_H
