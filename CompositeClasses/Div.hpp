#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <exception>

class Div : public Base{
    private:
        std::pair<Base*, Base*> operands;
    public:
        Div(Base* op1, Base* op2): operands(op1,op2) {}

        ~Div(){
            delete operands.first;
            delete operands.second;
        }
        
        double evaluate() {
            if(operands.second->evaluate() == 0){
                throw std::runtime_error("ErrorZeroDenominator");
            }
            return operands.first->evaluate() / operands.second->evaluate();
        }
        std::string stringify(){
            return "(" + operands.first->stringify() + " / " + operands.second->stringify() + ")";
        }

};

#endif // __DIV_HPP__