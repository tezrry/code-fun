#pragma once

#include "binary_tree/tree.h"
namespace binary_tree {

template<class T>
class TreapNode: public Node<T>
{
public:
    TreapNode(const T& value, int priority):Node<T>(value),priority_(priority) {}
private:
    int priority_;
};

template<class T>
class Treap
{
public:
    int Priority() {return 0;}

private:
    

    TreapNode<T> *_root;
};

}
