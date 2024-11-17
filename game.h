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

#include <SFML/Graphics.hpp>
#include "mainMenu.h"
#include "button.h"
#include "pause.h"
#include "inventory.h"


//Game class, add as needed, avoid subtracting 
class Game: public sf::Drawable
{
    public:
    Game();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    bool isDone() const;
    void update();
    bool startmenu;
    MainMenu mainMenu;//({450, 250},{500,500}); //Position, size
    Pause pauseMenu;
    Inventory inventoryMenu;//({450,250}, {400,400});

    protected:
    bool mIsDone;
    sf::Font mFont;
};

//Functions for misc stuff go here


#endif