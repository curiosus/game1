//
// Created by erudite on 1/17/16.
//

#include <iostream>
#include "Game.h"

Game::Game() :
        mWindow(sf::VideoMode(1600, 900), "PhuckMan"),
        mPlayer{}, mBots(), mBlocks() {

    mPlayer.setPosition(sf::Vector2f{50.0f, 800.0f});

//    for (int i = 0, j = 0; i < NUMBER_OF_BLOCKS; ++i, j += 4) {
//        mBlocks[i].setPosition(sf::Vector2f{blockData[j], blockData[j + 1]});
//        mBlocks[i].setDimensions(sf::Vector2f{blockData[j + 2], blockData[j + 3]});
//        mBlocks[i].setColor(sf::Color::Green);
//    }

    for (int i = 0, j = 0; i < NUMBER_OF_BLOCKS; ++i, j += 4) {
        Block *block = new Block{};
        block->setPosition(sf::Vector2f{blockData[j], blockData[j + 1]});
        block->setDimensions(sf::Vector2f{blockData[j + 2], blockData[j + 3]});
        block->setColor(sf::Color::Green);
        mBlocks.push_back(block);

    }

    std::vector<sf::Vector2f> botPositions;
    botPositions.push_back(sf::Vector2f{739.0f, 253.0f});
    botPositions.push_back(sf::Vector2f{1153.0f, 178.0f});
    botPositions.push_back(sf::Vector2f{966.0f, 631.0f});
    for (int i = 0; i < NUMBER_OF_BOTS; ++i) {
        Bot *bot = new Bot{};
        bot->setColor(sf::Color::Black);
        bot->setPosition(botPositions[i]);
        Player* pPlayer = &mPlayer;
        bot->setWorld(mBlocks, mBots, pPlayer);
        mBots.push_back(bot);
    }


}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                mPlayer.handleInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                mPlayer.handleInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::MouseButtonReleased:
                std::cout << sf::Mouse::getPosition(mWindow).x << ", " << sf::Mouse::getPosition(mWindow).y << std::endl;
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    detectCollisions();
    mPlayer.update(deltaTime);
    for (auto bot : mBots) {
        bot->update(deltaTime);
    }
}

void Game::render() {
    sf::Color color = sf::Color(39, 117, 159);
    mWindow.clear(color);
    for (auto block : mBlocks) {
        mWindow.draw(block->getShape());
    }
    for (auto bot : mBots) {
        mWindow.draw(bot->getShape());
        mWindow.draw(bot->getVision());
    }
    mWindow.draw(mPlayer.getShape());
    mWindow.display();
}


void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }

}

void Game::detectCollisions() {
    for (auto block : mBlocks) {

        bool collision = block->getShape().getGlobalBounds().intersects(mPlayer.getShape().getGlobalBounds());
        if (collision) {
            if (block->getShape().getSize().x == 25.0f) {
                sf::Vector2f force{1000.0f, 0.0f};
                mPlayer.absorbForce(force);
            } else {
                sf::Vector2f force{0.0f, 1000.0f};
                mPlayer.absorbForce(force);
            }
        }

        for (auto bot : mBots) {
            collision = block->getShape().getGlobalBounds().intersects(bot->getShape().getGlobalBounds());
            if (collision) {
                sf::Vector2f force = sf::Vector2f{10.0f, 10.0f};
                bot->absorbForce(force);
            }
            collision = bot->getShape().getGlobalBounds().intersects(mPlayer.getShape().getGlobalBounds());
            if (collision) {
                std::cout << "BAM" << std::endl;
            }
        }
    }
}

