//
// Created by hanil on 4/28/2023.
//

#ifndef SFML_PROJECTS_MOUSEEVENTS_H
#define SFML_PROJECTS_MOUSEEVENTS_H


#include <SFML/Graphics.hpp>

class mouseEvents
{
public:
    template<typename T>
    static bool isHovered(T& obj, sf::RenderWindow& window);
    template<typename T>
    static bool isClicked(T& obj, sf::RenderWindow& window);
};

#include "mouseEvents.cpp"


#endif //SFML_PROJECTS_MOUSEEVENTS_H
