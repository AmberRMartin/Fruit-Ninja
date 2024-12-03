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
    if (!mTexture.loadFromFile("Sprites/map background.png"))
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
    if (!mTreeTexture.loadFromFile("Sprites/map trees.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mTrees.setTexture(mTreeTexture);
    sf::Vector2u imageSize=mTreeTexture.getSize();
    mTrees.setOrigin(imageSize.x/2, imageSize.y/2);
    mTrees.setScale(size.x/mTreeTexture.getSize().x,size.y/mTreeTexture.getSize().y);
    mTrees.setPosition(position.x,position.y);
    Entity* temp;
    int arr[2] = {9,7};
    temp = new Entity(0,0,"Level 1", {675,475},{50,50}, sf::Color::Blue, arr, true);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 6;
    arr[1] = 7;
    temp = new Entity(50,50,"Level 1", {675,325},{50,50}, sf::Color::Blue, arr, false);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 1;
    arr[1] = 8;
    temp = new Entity(100,50,"Level 1", {765,75},{50,50}, sf::Color::Blue, arr, false);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 4;
    arr[1] = 5;
    temp = new Entity(150,50,"Level 2", {495,225},{50,50}, sf::Color::Blue, arr, false);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 6;
    arr[1] = 3;
    temp = new Entity(0,50,"Level 1", {315,325},{50,50}, sf::Color::Blue, arr, false);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 1;
    arr[1] = 4;
    temp = new Entity(0,100,"Level 3", {405,75},{50,50}, sf::Color::Blue, arr, false);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 8;
    arr[1] = 1;
    temp = new Entity(0,100,"Level 3", {135,425},{50,50}, sf::Color::Blue, arr, false);
    EntPtr.push_back(temp);
    mVectorSize++;
    arr[0] = 1;
    arr[1] = 1;
    temp = new Entity(0,100,"Level 4", {135,75},{60,60}, sf::Color::Blue, arr, false);
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
    target.draw(mTrees,states);
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
int Zone::validMove(int dir){
    int row = EntPtr[0]->getArrayPos(0);
    int col = EntPtr[0]->getArrayPos(1);
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
    return -1;
}
bool Zone::update(sf::Event& e, sf::RenderWindow& window){
    int row = EntPtr[0]->getArrayPos(0);
    int col = EntPtr[0]->getArrayPos(1);
    if(e.type == sf::Event::KeyPressed){
        if(e.key.code == sf::Keyboard::W){
            if(validMove(1) == 0){
                EntPtr[0]->setPosition(0,-50);
                Zone1[row][col] = '-';
                Zone1[row-1][col] = 'C'; 
                EntPtr[0]->setArrayPos(row-1,col);
                return false;
            }
            else if(validMove(1) == 1){
                for(int i = 1;i < mVectorSize; i++){
                    if(EntPtr[i]->mArrayPos[0] == row - 1){
                        if(EntPtr[i]->mArrayPos[1] == col){
                            Entity* temp = EntPtr[i];
                            EntPtr[i] = EntPtr[mVectorSize - 1];
                            delete temp;
                            EntPtr.push_back();
                        }
                    }
                }
                return true;
            }
           
        }
        else if(e.key.code == sf::Keyboard::D){
            if(validMove(2) == 0){
                EntPtr[0]->setPosition(50,0);
                Zone1[row][col] = '-';
                Zone1[row][col+1] = 'C';
                EntPtr[0]->setArrayPos(row,col+1); 
                return false;
            }
            else if(validMove(2) == 1){
                for(int i = 1;i < mVectorSize; i++){
                    if(EntPtr[i]->mArrayPos[0] == row){
                        if(EntPtr[i]->mArrayPos[1] == col+1){
                            Entity* temp = EntPtr[i];
                            EntPtr[i] = EntPtr[mVectorSize - 1];
                            delete temp;
                            EntPtr.push_back();
                        }
                    }
                }
                return true;
            }

        }
        else if(e.key.code == sf::Keyboard::S){
            if(validMove(3) == 0){
                EntPtr[0]->setPosition(0,50);
                Zone1[row][col] = '-';
                Zone1[row+1][col] = 'C'; 
                EntPtr[0]->setArrayPos(row+1,col);
                return false;
            }
            else if(validMove(3) == 1){
                for(int i = 1;i < mVectorSize; i++){
                    if(EntPtr[i]->mArrayPos[0] == row + 1){
                        if(EntPtr[i]->mArrayPos[1] == col){
                            Entity* temp = EntPtr[i];
                            EntPtr[i] = EntPtr[mVectorSize - 1];
                            delete temp;
                            EntPtr.push_back();
                        }
                    }
                }
                return true;
            }
        }
        else if(e.key.code == sf::Keyboard::A){
            if(validMove(4) == 0){
                EntPtr[0]->setPosition(-50,0); 
                Zone1[row][col] = '-';
                Zone1[row][col-1] = 'C';
                EntPtr[0]->setArrayPos(row,col-1);
                return false;
            }
            else if(validMove(4) == 1){
                for(int i = 1;i < mVectorSize; i++){
                    if(EntPtr[i]->mArrayPos[0] == row){
                        if(EntPtr[i]->mArrayPos[1] == col-1){
                            Entity* temp = EntPtr[i];
                            EntPtr[i] = EntPtr[mVectorSize - 1];
                            delete temp;
                            EntPtr.push_back();
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}