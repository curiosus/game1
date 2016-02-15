#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Time.hpp>
#include "Player.h"
#include "Block.h"

class Bot {

public:
    Bot();
    void move(sf::Vector2f movement);
    sf::CircleShape getShape();
    void setPosition(sf::Vector2f position);
    void update(sf::Time deltaTime);
    void setColor(sf::Color color);
    void absorbForce(sf::Vector2f forceVector);
    void setWorld(std::vector<Block*> blocks, std::vector<Bot*> bots, Player* player);



private:
    float mRadius = 25.0f;
    sf::CircleShape mShape;
    sf::Vector2f mDirection;
    sf::Vector2f mForceAbsorbed;
    std::vector<Block*> mBlocks;
    std::vector<Bot*> mBots;
    Player* mPlayer;



};

