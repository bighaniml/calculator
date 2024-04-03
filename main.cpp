#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Button.h"
#include "Calculator.h"

class RenderWindow;

int main() {


    sf::RenderWindow window(sf::VideoMode(500, 500, 32), "Test");
    Calculator c;
    Button b(sf::Color::Magenta, "5", 100,100);


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            c.eventHandle(window, event);
        }
        c.update();
        window.clear(sf::Color::Black);
        window.draw(c);
        window.display();
    }
    return 0;
}
