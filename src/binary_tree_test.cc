#include "gtest/gtest.h"
#include "binary_tree/treap.h"

TEST(BinaryTreeTest, Zero) 
{ 
    binary_tree::Treap<float> t;
    EXPECT_EQ(t.Priority(), 0);

    
    binary_tree::Node<binary_tree::Node<int>*> n(new binary_tree::Node<int>(1));
    EXPECT_EQ(n.Left, nullptr);
    
    EXPECT_EQ(1, 1); 
}