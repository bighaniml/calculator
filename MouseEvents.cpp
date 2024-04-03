//
// Created by hanil on 4/28/2023.
//
#ifndef SFML_PROJECTS_MOUSEEVENTS_CPP
#define SFML_PROJECTS_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<typename T>
bool mouseEvents::isHovered(T &obj, sf::RenderWindow &window)
{
    sf::Vector2f npos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return obj.getGlobalBounds().contains(npos);
}

template<typename T>
bool mouseEvents::isClicked(T &obj, sf::RenderWindow &window)
{
    return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif //SFML_PROJECTS_MOUSEEVENTS_CPP