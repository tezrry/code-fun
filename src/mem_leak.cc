#include "gtest/gtest.h"

TEST(MemLeak, Overflow)
{
    int ia[2];
    int *p = ia + 1;
    *p = 1;
}

TEST(MemLeak, Leak)
{
    int *p = new int[16];
    int *p2 = p + 1;
    delete[] p;
    *p2 = 1;
}