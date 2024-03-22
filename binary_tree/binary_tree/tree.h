#pragma once

#include <type_traits>
#include "base/comparable.h"

namespace binary_tree {

template<class T>
class Node : public code_fun::Comparable<T>
{
public:
    Node(const T& value):Left(nullptr),Right(nullptr),value_(value) {}
    virtual ~Node() {}

public:
    T& Value() {return this->value_;}

public:
    bool operator==(const Node &other) const
    {
        return this->value_ == other.value_;
    }
    bool operator>(const Node &other) const
    {
        return this->value_ > other.value_;
    }
    bool operator<(const Node &other) const
    {
        return this->value_ < other.value_;
    }

public:
    Node *Left;
    Node *Right;

protected:
    T value_;
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
