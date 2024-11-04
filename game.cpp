/**
 * @file game.cpp
 * @author Amber Martin, Nicholas Cicala, Matthew Barber
 * @brief 
 * @version 0.1
 * @date 2024-11-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "game.h"
#include "mainMenu.h"
#include "button.h"


//Game class
Game::Game()
{

    mIsDone = false;
    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        exit(1);
    }
    startmenu = false;
}


void Game::draw(sf::RenderTarget& target,sf::RenderStates states) const
{

}



