#include <iostream>
#include "Bot.h"

Bot::Bot() {
    mShape.setRadius(mRadius);
    mShape.setFillColor(sf::Color::Black);
    mVelocity.x = 100.0f;
    mVelocity.y = 100.0f;
    mRotationAngle = 90.0f;
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
        mVelocity.x *= (-1.0f);
        mVelocity.y *= (-1.0f);
    }

    sf::Vector2f movement{mVelocity.x, mVelocity.y};
    mVision.setPosition(mShape.getPosition());
    mVision.setSize(sf::Vector2f{30.0f, 250.0f});
    mVision.setOutlineColor(sf::Color::Black);
    mVision.setOutlineThickness(3.0f);
    mVision.setFillColor(sf::Color::Transparent);
    mVision.rotate(mRotationAngle);




    std::vector<Block*> blocksInView{};
    for (auto block : mBlocks) {
        sf::FloatRect blockRect = block->getShape().getGlobalBounds();
        sf::FloatRect visionRect = mVision.getGlobalBounds();
        sf::FloatRect thisRect = mShape.getGlobalBounds();
        if (blockRect.intersects(visionRect)) {
            blocksInView.push_back(block);
        }
    }

    for (auto blockInView : blocksInView) {

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
    mRotationAngle = 0.0f;
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

sf::RectangleShape Bot::getVision() {
    return mVision;
}
