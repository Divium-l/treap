//
// Created by Egor-Always-AFK on 07.12.2023.
//

#include <gtest/gtest.h>
#include "../src/DecartTree.hpp"

struct TestClass {
    int state;

    explicit TestClass(int state) : state(state) {}
    friend auto operator<=>(const TestClass &lhs, const TestClass &rhs) = default;
};

TEST(DecartTreeTest, CreateTreeSuccess) {
    auto *tree = new mit::DecartTree<int>();

    auto root = tree->getRoot();
    ASSERT_EQ(root, nullptr);
}


TEST(DecartTreeTest, InsertDataWithPriorityIntoTreeSuccess) {
    auto *tree = new mit::DecartTree<int>();

    tree->add(10, 100);
    tree->add(30, 120);
    tree->add(20, 10);

    auto root = tree->getRoot();

    ASSERT_EQ(root->value, 30);
    ASSERT_EQ(root->priority, 120);
    ASSERT_EQ(root->left->value, 10);
    ASSERT_EQ(root->left->priority, 100);
    ASSERT_EQ(root->left->right->value, 20);
    ASSERT_EQ(root->left->right->priority, 10);
}

TEST(DecartTreeTest, InsertTestClassDataWithPriorityIntoTreeSuccess) {
    auto *tree = new mit::DecartTree<TestClass>();

    tree->add(TestClass(10), 100);
    tree->add(TestClass(30), 120);
    tree->add(TestClass(20), 10);

    auto root = tree->getRoot();

    ASSERT_EQ(root->value.state, 30);
    ASSERT_EQ(root->priority, 120);
    ASSERT_EQ(root->left->value.state, 10);
    ASSERT_EQ(root->left->priority, 100);
    ASSERT_EQ(root->left->right->value.state, 20);
    ASSERT_EQ(root->left->right->priority, 10);
}

TEST(DecartTreeTest, InsertDataWithoutPriorityIntoTreeSuccess) {
	auto *tree = new mit::DecartTree<int>();

	tree->add(10);
	tree->add(100);
	tree->add(20);

	auto root = tree->getRoot();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}