#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Block.h"
#include "Player.h"
#include "Bot.h"

const static int NUMBER_OF_BLOCKS{19};
const static int BLOCK_ARRAY_SIZE{NUMBER_OF_BLOCKS * 4};
const static float  blockData[BLOCK_ARRAY_SIZE] = {0.0f, 0.0f, 1600.0f, 25.0f,
                                     0.0f, 0.0f, 25.0f, 900.0f,
                                     0.0f, 875.0f, 1600.0f, 25.0f,
                                     1575.0f, 0.0f, 25.0f, 900.0f,
                                     100.0f, 600.0f, 25.0f, 200.0f,
                                     150.0f, 100.0f, 25.0f, 200.0f,
                                     200.0f, 400.0f, 200.0f, 25.0f,
                                     250.0f, 750.0f, 200.0f, 25.0f,
                                     400.0f, 200.0f, 200.0f, 25.0f,
                                     550.0f, 600.0f, 25.0f, 200.0f,
                                     800.0f, 400.0f, 200.0f, 25.0f,
                                     700.0f, 130.0f, 200.0f, 25.0f,
                                     1400.0f, 150.0f, 25.0f, 200.0f,
                                     560.0f, 315.0f, 25.0f, 200.0f,
                                     1130.0f, 600.0f, 25.0f, 200.0f,
                                     850.0f, 520.0f, 25.0f, 200.0f,
                                     1000.0f, 120.0f, 25.0f, 200.0f,
                                     1240.0f, 480.0f, 200.0f, 25.0f,
                                     1280.0f, 650.0f, 200.0f, 25.0f};



const static int NUMBER_OF_BOTS{3};


class Game {
public:
    Game();
    void run();

public:
    const sf::Time TimePerFrame = sf::seconds(1.0f/ 60.0f);

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void detectCollisions();


private:
    sf::RenderWindow mWindow;
//    Block mBlocks[NUMBER_OF_BLOCKS];
    std::vector<Block*> mBlocks;
    Player mPlayer;
    std::vector<Bot*> mBots;
};