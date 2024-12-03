#ifndef Entity_H
#define Entity_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"



class Entity:World, public sf::Drawable
{
public:
    Entity(int rectL, int rectT,std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color, int ArrayPos[], bool PC);
    ~Entity(){};
    void setPosition(int hor, int vert);
    void setSize(sf::Vector2f  size);
    void setColor(sf::Color btnColor);
    void setText(std::string s);
    void setColorTextNormal(sf::Color textNormalColor){mTextNormal = textNormalColor;};
    void setArrayPos(int left, int right);

    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mObject.getGlobalBounds().width, mObject.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};
    int getArrayPos(int index);

    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    int mArrayPos[2] = {0,0};
private:
    
    sf::Color mObjColor;
    sf::Uint32 mBtnState;
    
    bool mPC = false;
    //text
    
    sf::Color mTextNormal;
};    
#endif
