#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base{
    private:
        std::pair<Base*, Base*> operands;
    public:
        Mult(Base* op1, Base* op2): operands(op1,op2) {}

        ~Mult(){
            delete operands.first;
            delete operands.second;
        }
        
        double evaluate() {
            return operands.first->evaluate() * operands.second->evaluate();
        }
        std::string stringify(){
            return "(" + operands.first->stringify() + " * " + operands.second->stringify() + ")";
        }

};

#endif // __MULT_HPP__