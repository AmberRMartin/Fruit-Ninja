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


/**
 * @brief Construct a new Game:: Game object
 * 
 */
Game::Game()
{

    mIsDone = false;
    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        exit(1);
    }
    startmenu = false;
//NOTE: Main, pause, and inventory menus are all using default constructors
//They are initialized by default and don't need edits -Amber

//Stats at the moment is here, also using it's default constructor.
//I don't know if it will stay when I get the battle menu -Amber

}

/**
 * @brief Levels up player's stats and changes inventory
 * 
 */
void Game::GlevelUp()
{
//Update internal stats
    stats.levelUp();
//Update displayed stats
    inventoryMenu.LV.setString("LV   " + std::to_string(stats.getLevel()));
    inventoryMenu.HP.setString("HP   " + std::to_string(stats.getHP()));
    inventoryMenu.ATK.setString("ATK  " + std::to_string(stats.getATK()));
}


