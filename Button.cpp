//
// Created by hanil on 10/12/2023.
//



#include "Button.h"


const sf::Color Button::orange      = sf::Color(254,160,12 );
const sf::Color Button::light       = sf::Color(165,165,165);
const sf::Color Button::dark        = sf::Color(52 ,52 ,52 );
const sf::Color Button::black       = sf::Color(0  ,0  ,0  );
const sf::Color Button::orangeHover = sf::Color(251,200,143);
const sf::Color Button::lightHover  = sf::Color(217,217,217);
const sf::Color Button::darkHover   = sf::Color(115,115,115);

Button::Button() {
    label.setString("");
    label.setFont(Font::getFont(POKER));
    circle.setFillColor(orange);
}

Button::Button(const sf::Color &color, const std::string &label, int x, int y, const std::string &type): x(x), y(y){
    this->label.setString(label);
    this->label.setFont(Font::getFont(POKER));
    circle.setFillColor(color);
    circle.setRadius(radius);
    circle.setPosition(x, y);
    helper::centerText(circle, this->label);
    this->type = type;
    if(type == "OP" || type == "EQ"){
        this->color = orange;
    }
    else if(type == "NUM"){
        this->color = dark;
    }
    else{
        this->color = light;
    }

}

//void Button::setColor(sf::Color color) {
//    circle.setFillColor(color);
//}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(circle);
    window.draw(label);
}

void Button::setUp()  {

}

int Button::getX() {
    return x;
}

int Button::getY() {
    return y;
}

void Button::setFontColor(const sf::Color& color) {
    label.setFillColor(color);
}

void Button::setColor(const sf::Color& color) {
    circle.setFillColor(color);
}

std::string Button::getLabel() {
    return label.getString();
}

sf::FloatRect Button::getGlobalBounds() const {
    return circle.getGlobalBounds();
}

std::string Button::getType() {
    return type;
}

sf::Color Button::getColor() {
    return this->color;
}

bool Button::hover(sf::Window &window)
{
    if ((pow((sf::Mouse::getPosition(window).x - (circle.getGlobalBounds().left + circle.getGlobalBounds().width/2)), 2) +
         pow((sf::Mouse::getPosition(window).y - (circle.getGlobalBounds().top + circle.getGlobalBounds().height/2)), 2)) <
        pow(circle.getRadius(), 2))
    {
//        std::cout << "Button Center:\nx: " << std::to_string(circle.getGlobalBounds().left + circle.getGlobalBounds().width/2) << "| y: " << (circle.getGlobalBounds().top + circle.getGlobalBounds().height/2) << std::endl;
//        std::cout << "Cursor Location:\nx: " << std::to_string(sf::Mouse::getPosition(window).x) << "| y: " << std::to_string(sf::Mouse::getPosition(window).y) << std::endl;
        return true;
    }
    return false;
}
