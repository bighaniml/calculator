//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_HELPER_CPP
#define SFML_PROJECTS_HELPER_CPP
#include "helper.h"
template<typename T>
void helper::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}
#endif