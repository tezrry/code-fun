#pragma once

#include "binary_tree/tree.h"

namespace binary_tree {

template<class T>
class Treap
{
public:
    int Priority() {return 0;}

private:
    template<class K>
    class TreapNode: public Node<K>
    {
    public:
        TreapNode(const K &value, int priority):Node<K>(value),_priority(priority) {}
    private:
        int _priority;
    };

    TreapNode<T> *_root;
};

}
