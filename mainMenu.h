#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"

enum state {normal, clicked};

class MainMenu: public Game
{
    public: 
    
    MainMenu();
    ~MainMenu();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    void handleInput(sf::Event& e, sf::RenderWindow& window);
    Button mStart;
    Button mExit;

    private:
    sf::Sprite mBackground;
    sf::Texture mBackTexture;
    sf::Text mTitle1;
    sf::Text mTitle2;
    sf::Color mTextColor;
    sf::Vector2f mPosition;
    //bool mIsDone;
    
};


    // void render();
    // void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    // void handleInput();

/*
Handleinput is for detecting if a button is clicked. All mouse-related
events go here.

draw is just drawing the buttons and screen
should be like three lines of item.draw();

Render is...idk what render is for. 
*/





class Button: public sf::Drawable
{
/*
Here to handle start and exit buttons
Including drawing them 
*/

    public:
    Button();
    Button(std::string s, sf::Vector2f position, sf::Vector2f size);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
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