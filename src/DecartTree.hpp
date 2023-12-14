//
// Created by Egor-Always-AFK on 01.10.2023.
//

#ifndef HEAP_DECARTTREE_H
#define HEAP_DECARTTREE_H

#include "Node.hpp"
#include "CComparable.hpp"
#include <utility>
#include <memory>

namespace mit {

    template<mit::CComparable T>
    class DecartTree {
    private:
        typedef std::shared_ptr<mit::Node<T>> Node;

        Node root;

        bool _contains(T value, Node node) {
			if (node == nullptr) {
				return false;
			} else if (node->value == value) {
				return true;
			} else if (node->value >= value) {
				return _contains(value, node->left);
			} else {
				return _contains(value, node->right);
			}
        }

        Node _merge(Node leftNode, Node rightNode) {
            if (!leftNode) {
                return rightNode;
            } else if (!rightNode) {
                return leftNode;
            } else {
                if (leftNode->priority > rightNode->priority) {
                    leftNode->right = _merge(leftNode->right, rightNode);
                    return leftNode;
                } else {
                    rightNode->left = _merge(leftNode, rightNode->left);
                    return rightNode;
                }
            }
        }

        std::pair<Node, Node> _split(Node node, T keyForSplit) {
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

        [[maybe_unused]] void merge(mit::DecartTree<T> treeForMerge) {
            this->root = _merge(this->root, treeForMerge.root);
        }

        [[maybe_unused]] std::pair<Node, Node> split(T keyForSplit) {
            auto [leftTree, rightTree] = _split(this->root, keyForSplit);
            this->root = leftTree;
            return {leftTree, rightTree};
        }

        [[maybe_unused]] void add(T value) {
            auto [leftTree, rightTree] = _split(this->root, value);
            auto newNode = Node(new mit::Node(value));

            this->root = _merge(leftTree, _merge(newNode, rightTree));
        }

        [[maybe_unused]] void add(T value, int priority) {
            auto [leftTree, rightTree] = _split(this->root, value);
            Node newNode = Node(new mit::Node(value, priority));
            this->root = _merge(leftTree, _merge(newNode, rightTree));
        }

        [[maybe_unused]] void addAll(T *values) {
            for (auto data: values) {
                this->add(data);
            }
        }

        [[maybe_unused]] bool contains(T value) {
            return _contains(value, this->root);
        }

        [[maybe_unused]] void clear() {
            root = nullptr;
        }

        [[maybe_unused]] void remove(T value) {
			if (this->contains(value)) {
				auto [left, right] = this->split(value);
				this->root = _merge(right, _merge(left->left, left->right));
			}
		}

        [[maybe_unused]] Node getRoot() {
            return root;
        }

		friend std::ostream& operator<<(std::ostream& ostream, mit::DecartTree<T>& tree) {
			return ostream;
		}
    };

} // mit

#endif //HEAP_DECARTTREE_H
