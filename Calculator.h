//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_CALCULATOR_H
#define SFML_PROJECTS_CALCULATOR_H

#include <vector>
#include "Postfix.h"
#include "Button.h"
#include "Screen.h"
#include "MouseEvents.h"
#include <SFML/Graphics.hpp>
class Calculator: public sf::Drawable {
private:
    std::string output = "";
    std::string ops = "/x-+=AC";
    std::vector<Button> buttons;
    Screen screen;
    sf::RectangleShape container;
    int gap = 10;
    int buttonRad = 50;
    void buttonSetUp();
    std::string makeRPNable(const std::string& output);

public:
    Calculator();
    void solve();
    void outputToScreen();
    virtual void eventHandle(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    bool isOperator(char op);
};


#endif //SFML_PROJECTS_CALCULATOR_H
