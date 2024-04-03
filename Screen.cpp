//
// Created by hanil on 10/12/2023.
//

#include "Screen.h"

Screen::Screen():Screen({150, 50}, Font::getFont(POKER)){

}

Screen::Screen(const sf::Vector2f &dimensions, const sf::Font &font) {
    box.setSize(dimensions);
    text.setFont(font);
    setText("5+7");
    helper::centerText(box, text);
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = box.getTransform();
    window.draw(box);
    window.draw(text, states);
}

void Screen::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
//    text.setPosition(position);
//    helper::centerText(box, text);
}

void Screen::setText(const std::string &label) {
    this->text.setString(label);
}

std::string Screen::getText() {
    return text.getString();
}

void Screen::clear() {
    text.setString("");
}

void Screen::setTextColor(const sf::Color &color) {
    text.setFillColor(color);
}

void Screen::setBackgroundColor(const sf::Color &color) {
    box.setFillColor(color);
}

void Screen::toggleDisplay() {

}

sf::Vector2f Screen::getDimension() {
    return box.getPosition();
}
