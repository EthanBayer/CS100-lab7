#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <random>

class Rand : public Base {
    private:
        double elem;
    public:
        Rand(): elem(0){}
        virtual double evaluate() { 
            elem = rand() % 100;
            return elem; 
        }
        virtual std::string stringify() { return std::to_string(elem); }
};

#endif //__RAND_HPP__
