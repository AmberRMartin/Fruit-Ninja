#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "game.h"

enum state {normal, hovered, clicked};

class MainMenu: public Game
{
    MainMenu();
    ~MainMenu();
    void render();
    void handleInput();
    void update();

    private:
    
    Button mStart;
    Button mExit;
    sf::Sprite mBackground;
    sf::Text mTitle1;
    sf::Text mTitle2;
    sf::Color mTextColor;
    
};

class Button: public MainMenu
{
/*
Here to handle start and exit buttons
Including drawing them 
*/

    public:
    Button();
    Button(std::string s, sf::Vector2f position, sf::Vector2f size);
    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};
    void update(sf::Event& e, sf::RenderWindow& window);


    private:
    sf::Sprite mButton;
    sf::Texture mTexture;
    sf::Text mText;
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    sf::Font mFont;
};

#endif