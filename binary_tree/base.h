#pragma once

namespace binary_tree {

template<class T>
class Node 
{
public:
    Node *Left;
    Node *Right;
    T value;
};

template<class T>
class Tree
{
public:
    Node<T> *Root;
};

}
