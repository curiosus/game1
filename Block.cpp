//
// Created by erudite on 1/17/16.
//

#include "Block.h"

Block::Block() {

}
void Block::setDimensions(sf::Vector2f wh) {
    mShape.setSize(wh);
}

void Block::setPosition(sf::Vector2f position) {
    mShape.setPosition(position.x, position.y);
}

sf::RectangleShape Block::getShape() {
    return mShape;
}

void Block::setColor(sf::Color color) {
    return mShape.setFillColor(color);
}

sf::Vector2f Block::getPosition() {
   return mShape.getPosition();
}
