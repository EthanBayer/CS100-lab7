#include <iostream>
#include <iomanip>
#include "ExpressionCalculator.hpp"

int main(int argc, char** argv){

    ExpressionCalculator calculate;
    Base* calc = calculate.parse(argv, argc);
    std::cout << "\n";
    std::cout << calc->stringify() << " = " << calc->evaluate() << std::endl;
    std::cout << "\n";
    return 0;
}