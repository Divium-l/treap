//
// Created by Egor-Always-AFK on 07.12.2023.
//

#include <gtest/gtest.h>
#include "../src/DecartTree.hpp"

TEST(DecartTreeTest, CreateTreeSuccess) {
    auto *tree = new mit::DecartTree<int>();

    auto root = tree->getRoot();
    ASSERT_EQ(root, nullptr);
}


TEST(DecartTreeTest, InsertIntoTreeSuccess) {
    auto *tree = new mit::DecartTree<int>();

    tree->add(10, 100);
    tree->add(30, 120);
    tree->add(20, 10);

    auto root = tree->getRoot();

    ASSERT_EQ(root->value, 10);
    ASSERT_EQ(root->priority, 100);
    ASSERT_EQ(root->left->value, 20);
    ASSERT_EQ(root->left->priority, 10);
    ASSERT_EQ(root->right->value, 30);
    ASSERT_EQ(root->right->priority, 120);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}