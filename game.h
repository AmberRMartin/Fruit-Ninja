/**
 * @file game.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 
/*
Game.h and Game.cpp are designed
to be edited as needed for various tasks.
If you need to edit preexisting code THAT IS NOT YOURS. ASK FOR PERMISSION OR I'LL PRESSURE WASH YOUR BONES -Amber
Good luck guys!
*/
#ifndef GAME_H
#define GAME_H


#include "mainMenu.h"
#include "button.h"
#include "pause.h"
#include "inventory.h"
#include "stats.h"
#include "battleScreen.h"

//Game class, add as needed, avoid subtracting 
class Game
{
    public:
    Game();

    bool isDone() const;
    void update();
    void GlevelUp();

//Variables
    bool startmenu;
    bool inBattle;

    MainMenu mainMenu;
    Pause pauseMenu;
    Inventory inventoryMenu;
    Stats stats;
    BattleScreen battleScreen;

    protected:
    bool mIsDone;
    sf::Font mFont;
};

//Functions for misc stuff go here


#endif