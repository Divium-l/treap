//
// Created by Egor-Always-AFK on 09.12.2023.
//

#include <gtest/gtest.h>
#include "../src/Node.hpp"

TEST(NodeTest, CreateNodeSuccess) {
    auto node = mit::Node<int>(10);

    ASSERT_EQ(10, node.value);
    ASSERT_TRUE(node.priority);
    ASSERT_EQ(nullptr, node.right);
    ASSERT_EQ(nullptr, node.left);
    ASSERT_EQ(nullptr, node.parent);
}

TEST(NodeTest, DifferentNodesHaveDifferentPriorities) {
    auto firstNode = mit::Node<int>(10);
    auto secondNode = mit::Node<int>(20);

    ASSERT_NE(firstNode.priority, secondNode.priority);
}
