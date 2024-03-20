#pragma once

#include "tree.h"

namespace binary_tree {

template<class T>
class Treap
{
public:
    

private:
    class TreapNode: public RawNode<T>
    {
    public:
        TreapNode(const T &value, int priority):RawNode(value),_priority(priority) {};
    private:
        int _priority;
    }

    TreapNode *_root;
};

}
