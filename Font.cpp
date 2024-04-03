//
// Created by hanil on 4/25/2023.
//

#include "Font.h"

std::map<fonts,sf::Font> Font::font;
sf::Font &Font::getFont(fonts f) {
    loadFont(f);
    return font.find(f)->second;
}

std::string Font::getPath(fonts f) {
    switch (f) {
        case(POKEMON):
            return "Font/PKMN RBYGSC.ttf";
        case(BUTTON):
            return "Font/KGDefyingGravity.ttf";
        case(POKER):
            return "Font/OpenSans-Bold.ttf";
    }
}

void Font::loadFont(fonts f) {
    sf::Font f1;
    f1.loadFromFile(getPath(f));
    if(font.count(f) == 0){
        font.insert({f, f1});
    }
}
