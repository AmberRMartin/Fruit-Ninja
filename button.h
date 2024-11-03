#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum state {normal, clicked};

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