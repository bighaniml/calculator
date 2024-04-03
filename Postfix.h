//
// Created by hanil on 10/10/2023.
//

#ifndef RPN_POSTFIX_H
#define RPN_POSTFIX_H
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>

class Postfix {
public:
    static std::string inFixToPostFix(std::string infix);
    //call above function in this function
    static double evaluate(std::string infix); //this is RPN

    static std::string getNextValue(std::string basicString);

    static bool isNumber(std::string basicString);

    static bool canBeInStack(std::stack<char> ops, std::string basicString);

    static double RPNEval(double left, double right, char op);
};


#endif //RPN_POSTFIX_H
