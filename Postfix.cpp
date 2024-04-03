//
// Created by hanil on 10/10/2023.
//

#include "Postfix.h"

std::string Postfix::inFixToPostFix(std::string infix) {
    //while string isn't empty keep getting the next thing to push into stack or queue
    std::stack<char> operators;
    std::string postfix;
    std::string next;
    while(!infix.empty()) {
        next = getNextValue(infix);
        infix = infix.substr(next.length(), infix.size() - 1);
        if (isNumber(next)) {
            postfix += next;
        } else {
            if (next[0] == '(') {
                operators.push(next[0]);
            } else if (next[0] == ')') {
                while (operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                if (operators.top() == '(')
                    operators.pop();
            } else if (canBeInStack(operators, next)) {
                operators.push(next[0]);
            } else {
                while (!canBeInStack(operators, next)) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(next[0]);
            }
        }
    }
    while(!operators.empty()){
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}


//double Postfix::evaluate(std::string infix) {
//    std::string postfix = inFixToPostFix(infix);
//    std::string next;
//    std::stack<double> numbers;
//    while(!postfix.empty()) {
//        //get next value and update postfix
//        next = getNextValue(postfix);
//        postfix = postfix.substr(next.length(), postfix.size() - 1);
//        if(isNumber(next)){
//            //if double more than one digit then turn it into the right number; 'change this to no quotes
//            if(next.length() > 1){
//                int stringToNum = 0;
//                for(int i = 0; i < next.length(); i++){
//                    stringToNum += (next[i]-'0') * pow(10, next.length()-2-i);
//                    std::cout << next[i];
//                }
//
//                numbers.push(stringToNum);
//                std::cout << "\nactual num: " << stringToNum << std::endl;
//            }
//                //if just one digit
//            else{
//                numbers.push(next[0]-'0');
//            }
//        }
//        else{
//            double solution;
//            char op = next[0];
//            double right = numbers.top();
//            numbers.pop();
//            double left = numbers.top();
//            numbers.pop();
////            std::cout << left << " " << op << " " << right << " = " << RPNEval(left, right, op )<< std::endl;
//            solution = RPNEval(left, right, op);
//            numbers.push(solution);
//        }
//    }
//    return numbers.top();
//
//}


double Postfix::evaluate(std::string infix) {
    std::string postfix = inFixToPostFix(infix);
    std::string next;
    std::stack<double> numbers;
    while(!postfix.empty()) {
        //get next value and update postfix
        next = getNextValue(postfix);
        postfix = postfix.substr(next.length(), postfix.size() - 1);
        if(isNumber(next)){
            //if double more than one digit then turn it into the right number; 'change this to no quotes
            if(next[0] == '\''){
                int stringToNum = 0;
                for(int i = 1; i < next.length()-1; i++){
                    stringToNum += (next[i]-'0') * pow(10, next.length()-2-i);
                }
                numbers.push(stringToNum);
            }
            //if just one digit
            else{
                numbers.push(next[0]-'0');
            }
        }
        else{
            double solution;
            char op = next[0];
            double right = numbers.top();
            numbers.pop();
            double left = numbers.top();
            numbers.pop();
//            std::cout << left << " " << op << " " << right << " = " << RPNEval(left, right, op )<< std::endl;
            solution = RPNEval(left, right, op);
            numbers.push(solution);
        }
    }
    return numbers.top();

}







std::string Postfix::getNextValue(std::string inFix) {
    std::string toReturn;
    if(inFix[0] == '\''){
        toReturn += '\'';
        int counter = 1;
        while(inFix[counter] != '\''){
            toReturn += inFix[counter];
            counter++;
        }
        toReturn += '\'';
        return toReturn;
    }
    else{
        toReturn += inFix[0];
        return toReturn;
    }

}


//std::string Postfix::getNextValue(std::string inFix) {
//    std::string toReturn;
//    if(std::isdigit(inFix[0]) && std::isdigit(inFix[1])){
//        toReturn += inFix[0];
//        int counter = 1;
//        while(std::isdigit(inFix[counter])){
//            toReturn += inFix[counter];
//            counter++;
//        }
//        return toReturn;
//    }
//    else{
//        toReturn += inFix[0];
//        return toReturn;
//    }
//
//}


bool Postfix::isNumber(std::string currentValue) {
    if(currentValue[0] >= 48 && currentValue[0] <= 57 || currentValue[0] =='\''){
        return true;
    }
    return false;
}

bool Postfix::canBeInStack(std::stack<char> ops, std::string next) {
    std::map<char, int> opPrecedence;
    opPrecedence['('] = 0;
    opPrecedence[')'] = -1;
    opPrecedence['+'] = 1;
    opPrecedence['-'] = 1;
    opPrecedence['*'] = 2;
    opPrecedence['/'] = 2;

    if(ops.empty())
        return true;
    else if(opPrecedence[next[0]] <= opPrecedence[ops.top()] || opPrecedence[next[0]] == -1 ) {
        return false;
    }
    return true;
}

double Postfix::RPNEval(double left, double right, char op) {
    switch(op){
        case '+':return left + right;
        case '-': return left - right;
        case '/': return left / right;
        case '*': return left * right;
    }
}

//cursed function try again
//std::string Postfix::inFixToPostFix(std::string infix) {
//    ///create a stack of chars and queue of strings
//    std::stack<char> operators;
//    std::string postfix;
//    ///any num surrounded by single quotes is not a digit --> make a function that does this
//    ///make a function that handles decimals
//    ///loop through infix string
//    int loop = 0;
//    while(!infix.empty()) {
//        std::cout << "loop: " << loop << '\n';
//        std::string next = getNextValue(infix); ///make this function and make it an outer loop
//        infix = infix.substr(next.length(), infix.length()-1);
//        ///if we see a number
//        if (isNumber(next))
//            ///push to queue
//            postfix += next;
//            ///if we see op
//        else {
//
//            ///if op can push to stack (not close parenthesis and higher op than prev op)
//            if (canBeInStack(operators, next)) {
//                ///then push
//                std::cout << "Can Be In Stack - current char: " << next << '\n';
//                std::cout << "here\n";
//                operators.push(next[0]);   //might be easier to make operators a string
//            }
//                ///else --> pop from stack and push to queue until you can push op into stack
//            else {
//
//                while (!canBeInStack(operators, next)) {
//                    std::cout << "Can't Be In Stack next: " << next << '\n';
//                    if(operators.top() != '(' && operators.top() != ')') {
//                        postfix.push_back(operators.top());
//                    }
//                    operators.pop();
//                }
//
//                operators.push(next[0]);
//            }
//        }
//        loop++;
//        std::cout << "current expression: " << postfix << '\n';
//    }
//
//    ///if we reach end of infix expression
//    /// ///pop everything from stack and push to queue
//    while(!operators.empty()){
//        if(operators.top() != '(' && operators.top() != ')') {
//            postfix.push_back(operators.top());
//            operators.pop();
//        } else{
//            operators.pop();
//        }
//    }
//
//    return postfix;
//}