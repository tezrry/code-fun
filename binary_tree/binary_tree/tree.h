#pragma once

#include <type_traits>
#include "base/comparable.h"
#include "base/template_util.h"

namespace binary_tree {

template<class T>
class Node : public code_fun::Comparable<T>
{
public:
    Node(const T& value):Left(nullptr),Right(nullptr),Value(value) {}

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
    T Value;
};

template<class T>
class Tree
{
public:
    Tree(int num):root_(nullptr),freeTail_(nullptr),buff_(num) 
    {
        static_assert(
            code_fun::is_derived_from_template<T, Node>::value, 
            "T MUST be derived from Node"
        );
    }

public:
    int Size() const {return buff_.size();}

private:
    T *root_;
    T *freeTail_;
    std::vector<T*> buff_;
};

}
