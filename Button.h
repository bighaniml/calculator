//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_BUTTON_H
#define SFML_PROJECTS_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Font.h"
#include "helper.h"

class Button : public sf::Drawable {
private:


    sf::Text label;
    sf::Color color;
    sf::CircleShape circle;
    std::string type;
    int radius = 25;
    int x;
    int y;
public:
    const static sf::Color orange;
    const static sf::Color light;
    const static sf::Color dark;
    const static sf::Color black;
    const static sf::Color orangeHover;
    const static sf::Color lightHover;
    const static sf::Color darkHover;
    int getX();
    int getY();
    //default constructor
    Button();
    //constructor
    Button(const sf::Color& color, const std::string& label, int x, int y, const std::string& type = "NUM");
//    //be able to change color
//    void setColor(sf::Color color);
    //draw
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //places label within button
    void setUp();
    void setFontColor(const sf::Color& color);
    void setColor(const sf::Color& color);
    std::string getLabel();
    sf::FloatRect getGlobalBounds() const;
    std::string getType();
    sf::Color getColor();
    bool hover(sf::Window &window);
};


#endif //SFML_PROJECTS_BUTTON_H
