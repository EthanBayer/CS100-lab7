

#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"

class Add : public Base
{
private:
  std::pair<Base*, Base*> children;
public:
  Add(Base* Op1, Base* Op2)
  {
    children.first = Op1;
    children.second = Op2;
  }
  virtual double evaluate()
  {
    return (children.first->evaluate() + children.second->evaluate());
  }

  virtual std::string stringify()
  {
    return ("(" + children.first->stringify() + " + " +  children.second->stringify() + ")");
  }

};
#endif //ADD_HPP

