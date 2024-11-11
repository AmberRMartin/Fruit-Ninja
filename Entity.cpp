/**
 * @file Entity.cpp
 * @author Matthew Barber
 * @brief definitions for Entity Class functions 
 * @date 2024-11-06
 */
#include "World.h"
/**
 * @brief Construct a new Entity:: Entity object
 * 
 * @param rectCord the starting cord to remove from sprite sheet
 * @param Wid the width of the sprite image
 * @param Len the length of the sprite image
 * @param arrayPos the position of the character in the map array of the zone class
 * @param pos the position of the object on the window
 * @param Player a bool check to see if this is the player character or not
 * @param cLevel the level of the entity
 * @param textF the file passed by reference of the text file
 * @param textureF the file passed by reference of the texture file
 */
Entity::Entity(nt rectL,int rectT int Wid, int Len, int arrayPos[], sf::Vector2f pos,
           bool Player, int cLevel){
    if (!mTexture.loadFromFile("")) //include file name
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mIsPlayer = Player;
    mObject.setTexture(mTexture); 
    mObject.setTextureRect(sf::IntRect(rectL, rectT, Wid, Len));
    sf::Vector2u imageSize=mTexture.getSize();
    mObject.setOrigin(imageSize.x/2, imageSize.y/2);
    mObject.setScale(size.x/mTexture.getSize().x,size.y/mTexture.getSize().y);
    mObject.setPosition(pos.x,pos.y);
    mPos = pos;
    mArrayPos[0] = arrayPos[0];
    mArrayPos[1] = arrayPos[1];
    if (!mFont.loadFromFile("")) //include file name 
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mText.setFont(mFont);
    unsigned int fontSize = mObject.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mLevel = cLevel;
    mText.setString("Level " + cLevel);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(pos.x, pos.y-fontSize/4);
    mText.setFillColor(sf::Color::White);
}