#include <gtest/gtest.h>
#include "../../ExpressionCalculator.hpp"

// Input and Base FIXTURE class for testing.

struct calc_input{
    int size;
    char** ar;
    double expected;
};


struct ParametrizedCalculatorTest: public ::testing::TestWithParam<calc_input> {
    ExpressionCalculator* calculator;
    ParametrizedCalculatorTest(){
        calculator = new ExpressionCalculator();
    }

    ~ParametrizedCalculatorTest(){
        delete calculator;
    }
};

//------------------- Testing valid experessions --------------------------------------------

TEST_P(ParametrizedCalculatorTest, ValidExpresssions){
    auto as = GetParam();
    EXPECT_NEAR(calculator->parse(as.ar, as.size)->evaluate(), as.expected, 0.0005);
}

INSTANTIATE_TEST_SUITE_P(ValidExpresssions, ParametrizedCalculatorTest,
    testing::Values(
        calc_input{4, new char*[4]{"./calculator","7", "*", "8"}, 56},
        calc_input{4, new char*[4]{"./calculator","7", "*", "-8"}, -56},
        calc_input{4, new char*[4]{"./calculator","-7", "*", "-8"}, 56},
        calc_input{4, new char*[4]{"./calculator","-6", "/", "3"}, -2},
        calc_input{4, new char*[4]{"./calculator","-6", "/", "-3"}, 2},
        calc_input{4, new char*[4]{"./calculator","-6", "**", "0"}, 1},
        calc_input{4, new char*[4]{"./calculator","4", "**", "2"}, 16},
        calc_input{4, new char*[4]{"./calculator","4", "**", "-2"}, 0.0625},
        calc_input{4, new char*[4]{"./calculator","345", "+", "74"}, 419},
        calc_input{4, new char*[4]{"./calculator","23", "-", "11"}, 12},
        calc_input{8, new char*[8]{"./calculator", "43", "+", "78", "*", "2", "/", "4"}, 60.5}
    )
);

//-------------------------- Testing Invalid Expressions ---------------------------------------

struct InvalidExpressionsTest : public ParametrizedCalculatorTest{};

TEST_P(InvalidExpressionsTest, InvalidExpresssions){
    auto as = GetParam();
    EXPECT_EQ(calculator->parse(as.ar, as.size), nullptr);
}

INSTANTIATE_TEST_SUITE_P(InvalidExpresssions, InvalidExpressionsTest,
    testing::Values(
        calc_input{4, new char*[4]{"./calculator","7", "4", "8"}, 0},
        calc_input{4, new char*[4]{"./calculator","+", "/", "3"}, 0},
        calc_input{4, new char*[4]{"./calculator","4", "**", "a"}, 0},
        calc_input{4, new char*[4]{"./calculator","34/", "+", "74"}, 0},
        calc_input{4, new char*[4]{"./calculator","23", "--", "11"}, 0},
        calc_input{8, new char*[8]{"./calculator", "43", "+", "78", "*", "2", "/", "*"}, 0}
    )
);