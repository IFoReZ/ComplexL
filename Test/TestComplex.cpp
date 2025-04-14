#include <gtest.h>
#include "Complex.h"

TEST(ComplexTest, Construct)
{
	Complex<double> BasicCompl;
	EXPECT_DOUBLE_EQ(BasicCompl.getReal(), 1);
	EXPECT_DOUBLE_EQ(BasicCompl.getImag(), 1);

	Complex<int> IntCreate(3, 2);
	EXPECT_EQ(IntCreate.getReal(), 3);
	EXPECT_EQ(IntCreate.getImag(), 2);
}

TEST(ComplexTest, Set)
{
	Complex<double> C;

	C.setReal(2.6);
	C.setImag(-1.5);

	EXPECT_DOUBLE_EQ(C.getReal(), 2.6);
	EXPECT_DOUBLE_EQ(C.getImag(), -1.5);
}

TEST(ComplexTest, opers)
{
	Complex<double> a(4, 4);
	Complex<double> b(2, 0);

	Complex<double> sum = a + b;

	EXPECT_DOUBLE_EQ(sum.getReal(), 6);
	EXPECT_DOUBLE_EQ(sum.getImag(), 4);

	Complex<double> dif = a - b;

	EXPECT_DOUBLE_EQ(dif.getReal(), 2);
	EXPECT_DOUBLE_EQ(dif.getImag(), 4);

	Complex<double> mult = a * b;

	EXPECT_DOUBLE_EQ(mult.getReal(), 8);
	EXPECT_DOUBLE_EQ(mult.getImag(), 8);

	Complex<double> div = a / b;

	EXPECT_DOUBLE_EQ(div.getReal(), 2);
	EXPECT_DOUBLE_EQ(div.getImag(), 2);
}

TEST(ComplexTest, True_False)
{
	Complex<double> a(1, 1);
	Complex<double> b(1, 1);
	Complex<double> c(1, 2);

	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a == c);
	EXPECT_FALSE(a != b);
	EXPECT_TRUE(a != c);
}