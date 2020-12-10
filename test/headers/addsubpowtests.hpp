#include <gtest/gtest.h>
#include "../../ExpressionCalculator.hpp"
#include <cstring>


TEST (AddSubPowTestSet, AddTests)
{
    ExpressionCalculator calculator;
    char* exp[10]{ " ", "7", "+", "9", "+", "12", "+", "34", "+", "132" };
    Base* test = calculator.parse(exp, 4);

    EXPECT_EQ(test->evaluate(), 16);

    Base* test2 = calculator.parse(exp, 6);

    EXPECT_EQ(test2->evaluate(), 28);

    Base* test3 = calculator.parse(exp, 8);

    EXPECT_EQ(test3->evaluate(), 62);

    Base* test4 = calculator.parse(exp, 10);

    EXPECT_EQ(test4->evaluate(), 194);

}

TEST (AddSubPowTestSet, SubTests)
{
    ExpressionCalculator calculator;
    char* exp[10]{ " ", "132", "-", "34", "-", "12", "-", "9", "-", "7" };
    Base* test5 = calculator.parse(exp, 4);

    EXPECT_EQ(test5->evaluate(), 98);

    Base* test6 = calculator.parse(exp, 6);

    EXPECT_EQ(test6->evaluate(), 86);

    Base* test7 = calculator.parse(exp, 8);

    EXPECT_EQ(test7->evaluate(), 77);

    Base* test8 = calculator.parse(exp, 10);

    EXPECT_EQ(test8->evaluate(), 70);

}

TEST (AddSubPowTestSet, PowTests)
{
    ExpressionCalculator calculator;
    char* exp[10]{ " ", "2", "*", "4", "*", "6", "*", "8", "*", "10" };
    Base* test5 = calculator.parse(exp, 4);

    EXPECT_EQ(test5->evaluate(), 8);

    Base* test6 = calculator.parse(exp, 6);

    EXPECT_EQ(test6->evaluate(), 48);

    Base* test7 = calculator.parse(exp, 8);

    EXPECT_EQ(test7->evaluate(), 384);

    Base* test8 = calculator.parse(exp, 10);

    EXPECT_EQ(test8->evaluate(), 3840);

}


