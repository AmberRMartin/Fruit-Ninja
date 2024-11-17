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

    // MainMenu temp1({450, 250},{500,500}); //Position, size
    // mainMenu = temp1;
    // mainMenu.fixFiles();

    // Inventory temp2({450,250}, {400,400});
    // inventoryMenu = temp2;

}


void Game::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
}



