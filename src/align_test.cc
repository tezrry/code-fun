#include "gtest/gtest.h"
#include "base/align.h"

TEST(AlignTest, AlignedNew)
{
    class test
    {
    public:
        test(int32_t i):i_(i) {}
        int32_t value() const {return i_;}
    private:
        int32_t i_;
    };
    //GTEST_LOG_(INFO) << "sizeof(test) == " << sizeof(test);
    class test2
    {
    public:
        test2(int32_t i):i_(i),c_(0) {}
        int32_t value() const {return i_;}
        char value2() const {return c_;}
    private:
        int32_t i_;
        char c_;
    };
    //GTEST_LOG_(INFO) << "sizeof(test2) == " << sizeof(test2);
    
    size_t size = 8;
    char *buf = new char[size];

    char *b = buf + 1;
    size -= 1;
    test *t = code_fun::AlignedNew<test, int32_t>(b, size, 1);
    EXPECT_EQ(1, t->value());
    EXPECT_EQ(0, size);

    b = buf;
    size = 8;
    test2 *t2 = code_fun::AlignedNew<test2, int32_t>(b, size, 2);
    EXPECT_EQ(2, t2->value());
    EXPECT_EQ(0, size);
    
    delete[] buf;
    // GTEST_LOG_(INFO) << "alignof " << alignof(align_test);
    // GTEST_LOG_(INFO) << "alignof " << alignof(align_max_test);
    //std::cout << "This will print to standard output." << std::endl;
    // GTEST_LOG_(INFO) << "sizeof " << sizeof(align_test);
    // GTEST_LOG_(INFO) << "sizeof " << sizeof(align_max_test);

    // GTEST_LOG_(INFO) << "sizeof " << sizeof(align_int);
    // GTEST_LOG_(INFO) << "sizeof " << sizeof(align_8);
}

TEST(AlignTest, SizeOfClass)
{
    class Base
    {
    public:
        int32_t i;
        virtual int32_t Value() const {return i;}
    };
    GTEST_LOG_(INFO) << "sizeof(Base) == " << sizeof(Base);

    class D1 : public Base
    {
        int32_t i;
        int32_t Value2() const {return i;}
    };
    GTEST_LOG_(INFO) << "sizeof(D1) == " << sizeof(D1);

    class D2 : public Base
    {
        int32_t i;
        virtual int32_t Value() const override {return i;}
    };
    GTEST_LOG_(INFO) << "sizeof(D2) == " << sizeof(D2);

    class D3 : public Base
    {
        int64_t i;
        int64_t Value2() const {return i;}
    };
    GTEST_LOG_(INFO) << "sizeof(D3) == " << sizeof(D3);
}
