/**
 * @file Zone.h
 * @author Matthew Barber
 * @brief Declaration for Zone Class
 * @date 2024-11-05
 */
#ifndef Zone_H
#define Zone_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"
#include "Entity.h"




class Zone:World, public sf::Drawable
{
public:
    Zone(int rectL, int rectT,std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~Zone(){
        while(mVectorSize != 0){
            mVectorSize--;
            delete EntPtr[mVectorSize];
            EntPtr.pop_back();
        }
    }
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f  size);
    void setColor(sf::Color btnColor);
    void setText(std::string s);
    void setColorTextNormal(sf::Color textNormalColor){mTextNormal = textNormalColor;};
    int validMove(int dir);

    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mObject.getGlobalBounds().width, mObject.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};


    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    vector<Entity*> EntPtr;
    int mVectorSize;
    sf::Color mObjColor;
    sf::Uint32 mBtnState;
    
    //text
    
    sf::Color mTextNormal;
    char Zone1[][10] =            {{'X', 'G', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},      
                                   {'X', '-', '-', '-', '-', '-', '-', '-', '-', 'X'},      
                                   {'X', '-', 'X', 'X', 'X', 'X', '-', 'X', '-', 'X'},      
                                   {'X', '-', 'X', 'X', 'X', '-', '-', 'X', '-', 'X'},      
                                   {'X', '-', 'X', 'X', 'X', '-', '-', 'X', '-', 'X'},      
                                   {'X', '-', 'X', 'X', 'X', '-', '-', '-', '-', 'X'},      
                                   {'X', '-', '-', '-', '-', 'X', 'X', '-', '-', 'X'},      
                                   {'X', '-', 'X', '-', '-', 'X', 'X', '-', '-', 'X'},      
                                   {'X', '-', 'X', '-', '-', '-', '-', '-', '-', 'X'},      
                                   {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'S', 'X', 'X'}};      
                                   

                                   
#endif
};