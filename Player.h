#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Time.hpp>

class Player {
public:
    Player();
    void move(sf::Vector2f movement);
    sf::CircleShape getShape();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    void handleInput(sf::Keyboard::Key key, bool isPressed);
    void update(sf::Time deltaTime);
    void setColor(sf::Color color);
    void absorbForce(sf::Vector2f vector2f);

private:
    float mRadius = 25.0f;
    sf::CircleShape mShape;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    float mSpeed; //TODO this should be a velocity vector
    sf::Vector2f mForceAbsorbed;

};