/**
 * @file mainMenu.cpp
 * @author Amber Martin
 * @brief Class definitions for Main Menu and Button
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "mainMenu.h"


/**
 * @brief Construct a new Main Menu:: Main Menu object
 * 
 */
MainMenu::MainMenu():MainMenu({0,0}, {0,0})
{
//Default, should not activate
}

MainMenu::MainMenu(sf::Vector2f position, sf::Vector2f size)
{
    mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png");
    if(!mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png"))
    {
        std::cout<< "Cannot open background texture";
    }
    mBackground.setTexture(mBackTexture);

    sf::Vector2u imageSize= mBackTexture.getSize();
    mBackground.setOrigin(imageSize.x/2, imageSize.y/2); //For centering
    mBackground.setScale(size.x/(mBackTexture.getSize().x),size.y/(mBackTexture.getSize().y));

    mPosition = position;
    mBackground.setPosition(mPosition.x, mPosition.y);

    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        std::cout<< "Issue loading font, main menu\n";
        exit(1);
    }

    mTitle1.setFont(mFont);
    mTitle2.setFont(mFont);
//Not actually sure what size to make the titles yet so lets go 1/5 size
    unsigned int fontSize = mBackground.getGlobalBounds().height/5;
    mTitle1.setCharacterSize(fontSize);
    mTitle2.setCharacterSize(fontSize);
    mTitle1.setString("Fruit");
    mTitle2.setString("Ninja!");
    mTitle1.setScale(200/size.x, 200/size.y);
    mTitle2.setScale(200/size.x, 200/size.y);
//insert title positions here
    mTitle1.setPosition(mPosition.x, mPosition.y-130);
    mTitle2.setPosition(mPosition.x+60, mPosition.y-80);

    mTextColor = sf::Color::White;
    mTitle1.setFillColor(mTextColor);
    mTitle2.setFillColor(mTextColor);

/*
    BUTTONS GO HERE
*/
//Button(std::string s, sf::Vector2f position, sf::Vector2f size);
    // Button temp1("Start", {(mPosition.x+30),mPosition.y}, {152,57});
    // Button temp2("Exit", {(mPosition.x+30), mPosition.y+90}, {152,57});
    // mStart = temp1;
    // mExit = temp2;

}


/**
 * @brief ONLY draws the objects for main menu.
 * 
 * @param target 
 * @param states 
 */
void MainMenu::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mBackground, states);
    target.draw(mTitle1, states);
    target.draw(mTitle2, states);
}



/**
 * @brief Takes the buttons inside main menu, checks for events
 * 
 * @param e 
 * @param window 
 */
void MainMenu::handleInput(sf::Event& e, sf::RenderWindow& window)
{
    // mStart.update(e, window);
    // mExit.update(e, window);
}


