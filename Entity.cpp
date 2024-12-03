/**
 * @file Entity.cpp
 * @author Matthew Barber
 * @brief definitions of Entity class functions
 * @date 2024-10-15
 */
#include "Entity.h"
#include "World.h"
/**
 * @brief Construct a new Button:: Button object
 * 
 * @param s text on the object
 * @param position position of the Entity on the display
 * @param size size of the Entity
 * @param color color of the Entity
 */
Entity::Entity(int rectL, int rectT,std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color, int ArrayPos[], bool PC){
    if (!mTexture.loadFromFile("Sprites/map_misc_sprites.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mObject.setTexture(mTexture);
    mObject.setTextureRect(sf::IntRect(rectL, rectT, size.x, size.y));
    sf::Vector2u imageSize={static_cast<unsigned int>(size.x),static_cast<unsigned int>(size.y)};
    mObject.setOrigin(imageSize.x/2, imageSize.y/2);

    mObject.setPosition(position.x,position.y);
    mPosition = position;
    mObjColor = color;
    if (!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mText.setFont(mFont);
    unsigned int fontSize = mObject.getGlobalBounds().height/5;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height);
    //set position at the middle of the button
    mText.setPosition(position.x, position.y -(mObject.getGlobalBounds().height * 0.3));
    mTextNormal = sf::Color::Red;
    mText.setFillColor(mTextNormal);
    mBtnState = norm;
    mArrayPos[0] = ArrayPos[0];
    mArrayPos[1] = ArrayPos[1];
    mPC = PC;
}

/**
 * @brief draws the buttom object
 * 
 * @param target 
 * @param states 
 */
void Entity::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    target.draw(mObject,states);
    if(!mPC)
        target.draw(mText,states);
}
/**
 * @brief sets the text of the object
 * 
 * @param s the string to change the text
 */
void Entity::setText(std::string s){
    unsigned int fontSize = mObject.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}
/**
 * @brief sets the possition of the object
 * 
 * @param position the new position of the object
 */
void Entity::setPosition(int hor, int vert){
    sf::Vector2f position = getPosition();
    mObject.setPosition(position.x+ hor,position.y + vert);
    mPosition = {position.x + hor, position.y + vert};
    unsigned int fontSize = mObject.getGlobalBounds().height/5;
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
   mText.setPosition(mPosition.x + hor, mPosition.y + vert);
}/**
 * @brief changes the size of the object and text
 * 
 * @param size the new size of the object
 */
void Entity::setSize(sf::Vector2f  size){
    sf::Vector2u imageSize=mTexture.getSize();
    mObject.setOrigin(imageSize.x/2, imageSize.y/2);
    mObject.setScale(size.x/mTexture.getSize().x,size.y/mTexture.getSize().y);
    unsigned int fontSize = mObject.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}
/**
 * @brief changes the color of the button
 * 
 * @param objColor the new color of the object
 */
void Entity::setColor(sf::Color objColor){
    mObjColor = objColor;
    mObject.setColor(objColor);
}
int Entity::getArrayPos(int index){
    if(index == 1 || index == 0){
        return mArrayPos[index];
    }
    return -1;
}
void Entity::setArrayPos(int left, int right){
    mArrayPos[0] = left;
    mArrayPos[1]= right;
}