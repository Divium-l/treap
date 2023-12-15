//
// Created by Egor-Always-AFK on 01.10.2023.
//

#ifndef HEAP_DECARTTREE_H
#define HEAP_DECARTTREE_H

#include "Node.hpp"
#include "CComparable.hpp"
#include <utility>
#include <memory>
#include <sstream>

namespace mit {

    /**
     * In computer science, the treap and the randomized binary search tree
     * are two closely related forms of binary search tree data structures
     * that maintain a dynamic set of ordered keys and allow binary searches
     * among the keys. After any sequence of insertions and deletions of keys,
     * the shape of the tree is a random variable with the same probability
     * distribution as a random binary tree; in particular, with high probability
     * its height is proportional to the logarithm of the number of keys, so that
     * each search, insertion, or deletion operation takes logarithmic time to perform.
     */
    template<mit::CComparable T> class DecartTree {
    private:
        typedef std::shared_ptr<mit::Node<T>> Node;

        Node root;

        /**
         * Recursive method for checking if element exists in the tree
         * @param value element to search for
         * @param node tree node to start checking from
         * @return true/false
         */
        bool contains_(T value, Node node) {
			if (node == nullptr) {
				return false;
			} else if (node->value == value) {
				return true;
			} else if (node->value >= value) {
				return contains_(value, node->left);
			} else {
				return contains_(value, node->right);
			}
        }

        /**
         * Recursive method for merging two trees into one
         * @param leftNode root of the first tree
         * @param rightNode root of the second tree
         * @return root of the new tree
         */
        Node merge_(Node leftNode, Node rightNode) {
            if (!leftNode) {
                return rightNode;
            } else if (!rightNode) {
                return leftNode;
            } else {
                if (leftNode->priority > rightNode->priority) {
                    leftNode->right = merge_(leftNode->right, rightNode);
                    return leftNode;
                } else {
                    rightNode->left = merge_(leftNode, rightNode->left);
                    return rightNode;
                }
            }
        }

        /**
         * Recursive method for splitting one tree by priority key into two
         * @param node node to split from
         * @param keyForSplit priority key
         * @return pair of roots
         */
        std::pair<Node, Node> split_(Node node, T keyForSplit) {
            if (!node) {
                return {nullptr, nullptr};
            } else {
                if (node->value <= keyForSplit) {
                    auto [left, right] = split_(node->right, keyForSplit);
                    node->right = left;
                    return {node, right};
                } else {
                    auto [left, right] = split_(node->left, keyForSplit);
                    node->left = right;
                    return {left, node};
                }
            }
        }

        /**
         * Recursive method that prints nodes into ostream
         * @param node node
         * @param ostream stream
         */
        static void inOrderPrint_(Node node, std::ostream& ostream) {
            if (node == nullptr) {
                return;
            }
            else {
                ostream << *node << ", ";
            }

            inOrderPrint_(node->left, ostream);
            inOrderPrint_(node->right, ostream);
        }

    public:
        DecartTree() : root(nullptr) {}
        ~DecartTree() = default;

        /**
         * Merges this tree with another tree
         * @param treeForMerge another tree
         */
        [[maybe_unused]] void merge(mit::DecartTree<T> treeForMerge) {
            this->root = merge_(this->root, treeForMerge.root);
        }

        /**
         * Splits tree on two subtrees
         * @param keyForSplit key for split
         * @return pair of subtrees
         */
        [[maybe_unused]] std::pair<Node, Node> split(T keyForSplit) {
            auto [leftTree, rightTree] = split_(this->root, keyForSplit);
            this->root = leftTree;
            return {leftTree, rightTree};
        }

        /**
         * Adds element to tree with random priority
         * @param value element
         */
        [[maybe_unused]] void add(T value) {
            auto [leftTree, rightTree] = split_(this->root, value);
            auto newNode = Node(new mit::Node(value));

            this->root = merge_(leftTree, merge_(newNode, rightTree));
        }

        /**
         * Adds element to tree with set priority
         * @param value element
         * @param priority priority
         */
        [[maybe_unused]] void add(T value, int priority) {
            auto [leftTree, rightTree] = split_(this->root, value);
            Node newNode = Node(new mit::Node(value, priority));
            this->root = merge_(leftTree, merge_(newNode, rightTree));
        }

        /**
         * Adds all elements from the array to the tree with random priority
         * @param values elements
         */
        [[maybe_unused]] void addAll(T values[]) {
            for (auto data: values) {
                this->add(data);
            }
        }

        /**
         * Checks if element is present in the tree
         * @param value element
         * @return true/false
         */
        [[maybe_unused]] bool contains(T value) {
            return contains_(value, this->root);
        }

        /**
         * Removes all elements from the tree
         */
        [[maybe_unused]] void clear() {
            root = nullptr;
        }

        /**
         * Removes requested element from the tree
         * @param value element
         */
        [[maybe_unused]] void remove(T value) {
			if (this->contains(value)) {
				auto [left, right] = this->split(value);
				this->root = merge_(right, merge_(left->left, left->right));
			}
		}

        /**
         * Returns root of the tree
         * @return root
         */
        [[maybe_unused]] Node getRoot() {
            return root;
        }

		friend std::ostream& operator<<(std::ostream& ostream, mit::DecartTree<T>& tree) {
            ostream << "Treap: [";
            inOrderPrint_(tree.root, ostream);
            ostream << "]";
            return ostream;
		}
    };

} // mit

#endif //HEAP_DECARTTREE_H
