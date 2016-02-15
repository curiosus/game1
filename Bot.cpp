#include <iostream>
#include "Bot.h"

Bot::Bot() {
    mShape.setRadius(mRadius);
    mShape.setFillColor(sf::Color::Black);
    mDirection.x = 100.0f;
    mDirection.y = 100.0f;
}

void Bot::move(sf::Vector2f movement) {
    mShape.move(movement);
}

sf::CircleShape Bot::getShape() {
    return mShape;
}

void Bot::setPosition(sf::Vector2f position) {
    mShape.setPosition(position);
}


void Bot::setColor(sf::Color color) {
    mShape.setFillColor(color);
}

void Bot::update(sf::Time deltaTime) {
    if (mForceAbsorbed.x != 0.0f || mForceAbsorbed.y != 0.0f) {
        mDirection.x *= (-1.0f);
        mDirection.y *= (-1.0f);
    }

    sf::Vector2f movement{mDirection.x, mDirection.y};

    sf::CircleShape visionRadius{};
    visionRadius.setPosition(mShape.getPosition());
    visionRadius.setRadius(50.0f);

    std::vector<Block*> blocksInView{};
    for (auto block : mBlocks) {
        if (block->getShape().getGlobalBounds().intersects(visionRadius.getGlobalBounds())) {
            blocksInView.push_back(block);
        }
    }

    std::vector<sf::Vector2f>* noBlocks{};
    Block* tmpBlock{};
    for (auto blockInView : blocksInView) {
        std::cout << blockInView->getPosition().x << ", " << blockInView->getPosition().y << std::endl;
        std::cout << blockInView->getShape().getPosition().x << ", " << blockInView->getShape().getPosition().y << std::endl;

    }
    std::cout << std::endl;

    /*
    if (evadeObstacle) {
        float xProximity = obstaclePosition.x - mShape.getPosition().x;
        float yProximity = obstaclePosition.y - mShape.getPosition().y;
        if (xProximity <= yProximity) {
           movement.x -= 100.0f;
           movement.y += 100.0f;
        } else {
            movement.x += 100.0f;
            movement.y -= 100.0f;
        }

    }

     */

    move(movement * deltaTime.asSeconds());
    mForceAbsorbed.x = 0.0f;
    mForceAbsorbed.y = 0.0f;
}


void Bot::absorbForce(sf::Vector2f forceVector) {
    mForceAbsorbed.x = forceVector.x;
    mForceAbsorbed.y = forceVector.y;
}

void Bot::setWorld(std::vector<Block *> blocks, std::vector<Bot *> bots, Player *player) {
    mPlayer = player;
    mBlocks = blocks;
    mBots = bots;

}
