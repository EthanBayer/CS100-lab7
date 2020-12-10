#pragma once

#include <iostream>
#include <map>
#include <functional>
#include "CompositeClasses/Op.hpp"
#include "CompositeClasses/base.hpp"
#include "CompositeClasses/Div.hpp"
#include "CompositeClasses/Mult.hpp"
#include "CompositeClasses/Pow.hpp"
#include "CompositeClasses/Rand.hpp"
#include "CompositeClasses/Sub.hpp"
#include "CompositeClasses/Add.hpp"

//A Functor 
//
/*
    int foo();

    fucntion<int()> bar = foo;

    bar(); // calls foo()
// Lambda function
    [pass variables here](parameters){body}

// Map with Lambda function: look up table

*/

class ExpressionCalculator
{
    private:
        bool checkifdigit(std::string str){
            for (char a : str){
                if (!isdigit(a)){
                    if(a == '-' && str.size() > 1){
                        continue;
                    }
                    return false;
                }
            }
            return true;
        }

        Base* result = nullptr;
        std::map<std::string, std::function<void (Base*)>> selectOption{
            {"+", [this](Base* second){ this->result = new Add(this->result, second);}},
            {"-", [this](Base* second){ this->result = new Sub(this->result, second);}},
            {"*", [this](Base* second){ this->result = new Mult(this->result, second);}},
            {"/", [this](Base* second){ this->result = new Div(this->result, second);}},
            {"**", [this](Base* second){ this->result = new Pow(this->result, second);}}
        };
        
    public: 
        Base* parse(char** argv, int length)
        {
            result = checkifdigit(argv[1]) ? new Op((std::stoi(argv[1]))): nullptr;
            if(!result){return nullptr;}
            char* operation;

            for (int i = 2; i < length-1; i++)
            {
                operation = argv[i];

                if (selectOption.find(operation)  != selectOption.end())
                {
                    if (checkifdigit(argv[i + 1]))
                    {
                        selectOption[operation](new Op(std::stoi(argv[++i])));
                        continue;
                    }
                    std::cout << "NOT A DIGIT!!!!!!!!!!!!\n\n";
                    return nullptr;
                }
                else
                {
                    std::cout << "OPERATION NOT SUPPORTED\n\n";
                    return nullptr;
                }
            }
            return result;
        }

};