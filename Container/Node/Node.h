//
// Created by Egor-Always-AFK on 26.09.2023.
//

#ifndef NODE_H
#define NODE_H


namespace mit {

    template <class T> class Node {
    public:
        explicit Node() = default;
        explicit Node(T key) : key(key) {}
        explicit Node(T key, int priority, Node *left, Node *right);
        ~Node();
        void split();
        void merge();
        void insert();
        void erase();
    private:
        T key;
        int priority{};
        Node *left;
        Node* right;
    };


} // mit

#endif //NODE_H
