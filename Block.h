#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class Block {

public:
    Block();
    void setDimensions(sf::Vector2f wh);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    sf::RectangleShape getShape();
    void setColor(sf::Color color);

private:
    sf::RectangleShape mShape;
};