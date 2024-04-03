//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_HELPER_H
#define SFML_PROJECTS_HELPER_H
#include <SFML/Graphics.hpp>
#include <cmath>

class helper {
public:
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
};

#include "helper.cpp"
#endif //SFML_PROJECTS_HELPER_H
