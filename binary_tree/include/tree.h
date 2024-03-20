#pragma once

#include <type_traits>
#include "base/include/comparable.h"

namespace binary_tree {

template<class T>
class Node : public Comparable
{
public:
    Node(const T &value):_value(value),Left(nullptr),Right(nullptr)
    {
        std::static_assert(
            std::is_base_of<Comparable, T> || std::is_integral<T>::value, 
            "T MUST be Comparable or integer"
        );
    }
    virtual ~Node() {}

public:
    virtual bool operator==(const Node &other) const
    {
        return _value == other._value;
    }
    virtual bool operator>(const Node &other) const
    {
        return _value > other._value;
    }
    virtual bool operator<(const Node &other) const
    {
        return _value < other._value;
    }

public:
    Node *Left;
    Node *Right;

private:
    T _value;
};

template<class T>
class Tree
{
public:
    Tree():_num(0),_root(nullptr) {}
    Tree(int num):_num(num) {}
    virtual ~Tree() {}

private:
    bool fixed;
    int _num;
    
    T *_root;
};

}
