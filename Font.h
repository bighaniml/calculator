//
// Created by hanil on 4/25/2023.
//

#ifndef SFML_PROJECTS_FONT_H
#define SFML_PROJECTS_FONT_H
#include<SFML/Graphics.hpp>
#include "fonts.h"

class Font {
private:
    static std::map<fonts, sf::Font> font;
    static void loadFont(fonts f);
    static std::string getPath(fonts f);
public:
    static sf::Font& getFont(fonts f);
};




#endif //SFML_PROJECTS_FONT_H
