#include "gtest/gtest.h"
#include "binary_tree/treap.h"

TEST(BinaryTreeTest, Zero) 
{ 
    binary_tree::Tree<binary_tree::Node<int>> tni(10);
    //binary_tree::Tree<int> f(1);
    binary_tree::Tree<binary_tree::TreapNode<int> > ti(10);
    
    //binary_tree::Node<binary_tree::Tree<binary_tree::Node<int>>> n(tni);
    //EXPECT_EQ(n.Left, nullptr);
    
    EXPECT_EQ(1, 1); 
}