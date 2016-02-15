//
// Created by erudite on 1/19/16.
//

#include <iostream>
#include "Player.h"


Player::Player() {
   mShape.setRadius(mRadius);
   mShape.setFillColor(sf::Color::Yellow);
   mSpeed = 0.0f;
}

void Player::move(sf::Vector2f movement) {
    mShape.move(movement);
}

sf::CircleShape Player::getShape() {
    return mShape;
}

void Player::setPosition(sf::Vector2f position) {
    mShape.setPosition(position);
}

sf::Vector2f Player::getPosition() {
    return mShape.getPosition();
}

void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::W :
           mSpeed = 100.0f;
           mIsMovingUp = isPressed;
           break;
        case sf::Keyboard::S :
            mSpeed = 100.0f;
           mIsMovingDown = isPressed;
           break;
        case sf::Keyboard::A :
            mSpeed = 100.0f;
            mIsMovingLeft = isPressed;
            break;
        case sf::Keyboard::D :
            mSpeed = 100.0f;
            mIsMovingRight = isPressed;
            break;
    }
}

void Player::update(sf::Time deltaTime) {
    sf::Vector2f movement{0.0f, 0.0f};

    if (mIsMovingUp) {
        movement.y -= mSpeed;
    }

    if (mIsMovingDown) {
        movement.y += mSpeed;
    }

    if (mIsMovingLeft) {
       movement.x -= mSpeed;
    }

    if (mIsMovingRight) {
       movement.x += mSpeed;
    }


    if (mForceAbsorbed.x > 0.0f) {
       if (movement.x <= 0.0f) {
          movement.x += mForceAbsorbed.x;
       } else {
          movement.x -= mForceAbsorbed.x;
       }
    }

    if (mForceAbsorbed.y > 0.0f) {
        if (movement.y <= 0.0f) {
           movement.y += mForceAbsorbed.y;
        } else {
            movement.y -= mForceAbsorbed.y;
        }
    }

    move(movement * deltaTime.asSeconds());
    mForceAbsorbed.x = 0.0f;
    mForceAbsorbed.y = 0.0f;

}

void Player::setColor(sf::Color color) {
    mShape.setFillColor(color);
}

void Player::absorbForce(sf::Vector2f vector2f) {
   mForceAbsorbed.x = vector2f.x;
   mForceAbsorbed.y = vector2f.y;

}
