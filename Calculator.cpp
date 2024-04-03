//
// Created by hanil on 10/12/2023.
//

#include "Calculator.h"

Calculator::Calculator() {
    buttonSetUp();
    screen.setPosition(sf::Vector2f(0,0));
    screen.setText(output);
    screen.setBackgroundColor(Button::black);

}

void Calculator::solve() {

}

void Calculator::outputToScreen() {

}

void Calculator::eventHandle(sf::RenderWindow &window, sf::Event event) {

    for (Button &b: buttons) {
        if (mouseEvents::isClicked(b, window)) {
            if (b.getType() == "OP" || b.getType() == "NUM") {
                if (b.getType() == "OP" && (output.length() != 0 && isOperator(output.at(output.size() - 1)))) {
                    output.at(output.size() - 1) = b.getLabel().at(0);
                } else {
                    if (b.getLabel() == "x") {
                        output += '*';
                    } else {
                        output += b.getLabel();
                    }
                }
            }
            if (b.getType() == "CLEAR") {
                output = "";
            }
            if (b.getType() == "EQ") {
                std::string rpnable = makeRPNable(output);
                output = std::to_string(Postfix::evaluate(rpnable));
            }
        }
        if (/*mouseEvents::isHovered(b, window)*/ b.hover(window) ) {
            if(b.getType() == "OP" || b.getType() == "EQ") {
                b.setColor(Button::orangeHover);
            }
            if(b.getType() == "NUM"){
                b.setColor(Button::darkHover);
            }
            else{
                b.setColor(Button::lightHover);
            }
        }
        else {
            b.setColor(b.getColor());
        }
    }
}

void Calculator::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i = 0; i < buttons.size(); i++){
        window.draw(buttons.at(i));
    }
    window.draw(screen);
}

void Calculator::buttonSetUp() {
    //make all the number buttons
    for(int i = 0; i < 10; i++){
        std::string label = std::to_string(i);
        if(i == 0) {
            int yVal = 5*(buttonRad+gap);
            buttons.push_back(Button(Button::dark, label, gap, yVal, "NUM"));
        }
        else{
            int yVal;
            int xVal;
            //handle buttons 1-3 only y val
            if(i >= 1 && i <= 3){
                yVal = 4*(buttonRad+gap);
                xVal = (i-1)*(buttonRad + gap) + gap;
            }
                //handle buttons 4-7
            else if(i >= 4 &&  i <= 6){
                yVal = 3*(buttonRad+gap);
                xVal = (i%4)*(buttonRad + gap) + gap;
            }
                //handle buttons 7-9
            else if(i >= 7 &&  i <= 9){
                yVal = 2*(gap + buttonRad);
                xVal = (i%7)*(buttonRad + gap) + gap;
            }
            buttons.push_back(Button(Button::dark, label, xVal, yVal, "NUM"));
        }
    }

    //make ops button
    int xValZero = buttons.at(0).getX();
    int xVal = xValZero + 3*(gap+buttonRad);
    for(int i = 0; i < 5; i++){
        std::string label = ops.substr(i, 1);
        if( i == 4){
            buttons.push_back(Button(Button::orange, label, xVal, (i+1)*(buttonRad+gap), "EQ"));
        }
        else {
            buttons.push_back(Button(Button::orange, label, xVal, (i + 1) * (buttonRad + gap), "OP"));
        }
    }
    //clear button
    std::string label = ops.substr(5, 2);

    buttons.push_back(Button(Button::light, label, xValZero, buttonRad+gap, "CLEAR"));
    buttons.at(buttons.size()-1).setFontColor(Button::dark);
}

void Calculator::update() {
    screen.setText(output);

}

bool Calculator::isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '/' || ch == 'x'){
        return true;
    }
    return false;
}

std::string Calculator::makeRPNable(const std::string &output) {
    std::string toReturn;
    std::string outputCpy = output;
    std::string next;
    while(!outputCpy.empty()) {
        if (outputCpy.length() > 1 && std::isdigit(outputCpy[0]) && std::isdigit(outputCpy[1])) {
            int counter = 0;
            while (std::isdigit(outputCpy[counter])) {
                next += outputCpy[counter];
                counter++;
            }
            outputCpy = outputCpy.substr(next.length(), outputCpy.size());
            next.insert(0, "\'");
            next += "\'";
        } else {
            next += outputCpy[0];
            outputCpy = outputCpy.substr(next.length(), outputCpy.size());
        }
        toReturn += next;
        next = "";
    }
    return toReturn;
}
