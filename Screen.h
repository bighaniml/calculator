//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_SCREEN_H
#define SFML_PROJECTS_SCREEN_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Font.h"
#include "helper.h"


class Screen : public sf::Drawable{
private:
    sf::RectangleShape box;
    sf::Text text;
//    sf::Font font;
public:
    Screen();
    Screen(const sf::Vector2f &dimensions, const sf::Font &font);
    void setPosition(const sf::Vector2f &position);
    void setText(const std::string& label);
    std::string getText();
    void clear();
    void setTextColor(const sf::Color &color);
    void setBackgroundColor(const sf::Color& color);
    void toggleDisplay();
    sf::Vector2f getDimension();

protected:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECTS_SCREEN_H
