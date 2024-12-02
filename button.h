/**
 * @file button.h
 * @author Amber Martin
 * @brief The button class for reusing across as many menus as needed
 * @version 0.1
 * @date 2024-11-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum state {normal, clicked};

class Button: public sf::Drawable
{

    public:
    Button();
    Button(std::string s, sf::Vector2f position, sf::Vector2f size);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};
    bool clicked(sf::Event& e, sf::RenderWindow& window);
    bool hover(sf::Event& e, sf::RenderWindow& window);
    void fixFiles();

    private:
    sf::Sprite mButton;
    sf::Texture mTexture;
    sf::Text mText;
    sf::Vector2f mPosition; 
    sf::Uint32 mBtnState;
    sf::Font mFont;
};

#endif