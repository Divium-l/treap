//
// Created by Divium on 11.12.2023.
//
#include "DecartTree.hpp"

void fillTree() {
	auto tree = mit::DecartTree<int>();

	for (int i = 0; i < 1000; i++) {
		tree.add(rand());
	}
}

int main() {
	for (int i = 0; i < 100; i++) {
		fillTree();
	}

    return 0;
}
