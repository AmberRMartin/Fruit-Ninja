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
   // ~MainMenu();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    void handleInput(sf::Event& e, sf::RenderWindow& window);
    void resize(sf::RenderWindow &window);
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
    //bool mIsDone;
    
};


#endif