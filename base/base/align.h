#pragma once

namespace code_fun
{
    constexpr int INT_SIZE = sizeof(void*);

    template <class T, class... Args>
    T* AlignedNew(char*& buf, size_t& size, Args ...args)
    {
        size_t ts = sizeof(T);
        if (size < ts) {
            return nullptr;
        }

        unsigned long mask = alignof(T) - 1;
        unsigned long ptr = reinterpret_cast<unsigned long>(buf);
        ptr = (ptr + mask) & ~mask;

        char *curr = reinterpret_cast<char*>(ptr);
        if (curr + ts - buf > size)
        {
            return nullptr;
        }
        T *ret = new (curr) T(args...);

        curr += ts;
        size -= curr - buf;
        buf = curr;
        return ret;
    }

    
}
struct alignas(std::max_align_t) align_max_test
{
    char c;
};

struct align_test
{
    char c;
};

struct alignas(int) align_int
{
    char c;
};

struct alignas(8) align_8
{
    char c;
};
