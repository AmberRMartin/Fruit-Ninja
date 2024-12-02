/**
 * @file Zone.cpp
 * @author Matthew Barber
 * @brief definitions of Entity class functions
 * @date 2024-10-15
 */
#include "Zone.h"
#include "World.h"
/**
 * @brief Construct a new Zone:: Zone object
 * 
 * @param s text on the object
 * @param position position of the Zone on the display
 * @param size size of the Zone
 * @param color color of the Zone
 */
Zone::Zone(int rectL, int rectT,std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color){
    mVectorSize =0;
    if (!mTexture.loadFromFile("R.jpg"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mObject.setTexture(mTexture);
    sf::Vector2u imageSize=mTexture.getSize();
    mObject.setOrigin(imageSize.x/2, imageSize.y/2);
    mObject.setScale(size.x/mTexture.getSize().x,size.y/mTexture.getSize().y);
    
    mObject.setPosition(position.x,position.y);
    mPosition = position;
    mObjColor = color;
    mBtnState = normal;
    Entity* temp;
    temp = new Entity(10,10,"Level 1", {300,250},{150,100}, sf::Color::Blue, {0,0}, false);
    EntPtr.push_back(temp);
    mVectorSize++;
}

/**
 * @brief draws the Zone object
 * 
 * @param target 
 * @param states 
 */
void Zone::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    target.draw(mObject,states);
    for(int i = 0; i < mVectorSize; i++)
        target.draw(*EntPtr[i]);
}
/**
 * @brief sets the text of the object
 * 
 * @param s the string to change the text
 */
void Zone::setText(std::string s){
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
void Zone::setPosition(sf::Vector2f position){
    mObject.setPosition(position.x,position.y);
    mPosition = position;
    unsigned int fontSize = mObject.getGlobalBounds().height/2;
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}/**
 * @brief changes the size of the object and text
 * 
 * @param size the new size of the object
 */
void Zone::setSize(sf::Vector2f  size){
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
void Zone::setColor(sf::Color objColor){
    mObjColor = objColor;
    mObject.setColor(objColor);
}
/**
 * @brief checks if the movement is valid
 * 
 * @param dir the intended direction, 1 N 2 E 3 S 4 W
 * @return int returns an int for if invalid move (-1), valid move(0), or entering combat(1)
 */
int validMove(int dir){
    int row = EntPtr[0].mArrayPos[0];
    int col = EntPtr[0].mArrayPos[1];
    if(dir == 1){
        if(row > 0){
            if(Zone1[row-1][col] == 'X')
                return -1;
            else if(Zone1[row-1][col] == '-')
                return 0;
            else if(Zone1[row-1][col] == 'E')
                return 1;
        }
    }
    else if(dir == 2){
         if(col < 10){
            if(Zone1[row][col+1] == 'X')
                return -1;
            else if(Zone1[row][col+1] == '-')
                return 0;
            else if(Zone1[row][col+1] == 'E')
                return 1;
        }
    }
    else if(dir == 3){
         if(row < 10){
            if(Zone1[row+1][col] == 'X')
                return -1;
            else if(Zone1[row+1][col] == '-')
                return 0;
            else if(Zone1[row+1][col] == 'E')
                return 1;
        }
    }
    else if(dir == 4){
        if(col < 10){
            if(Zone1[row][col-1] == 'X')
                return -1;
            else if(Zone1[row][col-1] == '-')
                return 0;
            else if(Zone1[row][col-1] == 'E')
                return 1;
        }
    }
    else{
        return -1;
    }
}