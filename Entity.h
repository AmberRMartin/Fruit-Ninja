#ifndef Entity_H
#define Entity_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"


enum state {normal};

class Entity:World, public sf::Drawable
{
public:
    Entity(int rectL, int rectT,std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    Entity(){};
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f  size);
    void setColor(sf::Color btnColor);
    void setText(std::string s);
    void setColorTextNormal(sf::Color textNormalColor){mTextNormal = textNormalColor;};


    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mObject.getGlobalBounds().width, mObject.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};


    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    
    sf::Color mObjColor;
    sf::Uint32 mBtnState;
    
    //text
    
    sf::Color mTextNormal;
#endif
};