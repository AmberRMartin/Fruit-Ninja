/**
 * @file mainMenu.h
 * @author Amber Martin
 * @brief Creates and draws main menu, minus the buttons for it
 * @version 0.1
 * @date 2024-11-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"


class MainMenu: public sf::Drawable
{
    public: 
    MainMenu();
    MainMenu(sf::Vector2f position, sf::Vector2f size);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    void fixFiles();
    Button mStart;
    Button mExit;

    private:
    sf::Sprite mBackground;
    sf::Texture mBackTexture;
    sf::Text mTitle1;
    sf::Text mTitle2;
    sf::Color mTextColor;
    sf::Vector2f mPosition;
    sf::Font mFont;
    
};


#endif