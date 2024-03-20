#pragma once

namespace code_fun {

class Comparable
{
public:
    virtual bool operator==(const Comparable& other) const = 0;
    virtual bool operator>(const Comparable& other) const = 0;
    virtual bool operator<(const Comparable& other) const = 0;
    
    bool operator!=(const Comparable& other) const
    {
        return !(*this == other);
    }
    bool operator>=(const Comparable& other) const
    {
        return (*this > other) || (*this == other);
    }
    bool operator<=(const Comparable& other) const
    {
        return (*this < other) || (*this == other);
    }
};





}