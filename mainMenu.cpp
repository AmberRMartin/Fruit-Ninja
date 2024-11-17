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
MainMenu::MainMenu():MainMenu({450, 250},{500,500})
{
//Default, should not activate
//Could I have just had this as the only constructor? Yes! But the other way is easier for adjusting from main
}

/**
 * @brief Construct a new Main Menu:: Main Menu object
 * 
 * @param position Position of main image
 * @param size Size of image
 */
MainMenu::MainMenu(sf::Vector2f position, sf::Vector2f size)
{
    mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png");
    if(!mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png"))
    {
        std::cout<< "Cannot open background texture";
        exit(1);
    }
    mBackground.setTexture(mBackTexture);

//Size stuff
    sf::Vector2u imageSize= mBackTexture.getSize();
    mBackground.setScale(size.x/(mBackTexture.getSize().x),size.y/(mBackTexture.getSize().y));

//Positioning
    mBackground.setOrigin(imageSize.x/2, imageSize.y/2); //For centering
    mPosition = position;
    mBackground.setPosition(mPosition.x, mPosition.y);

//The following is all fonts and titles
    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        std::cout<< "Issue loading font, main menu\n";
        exit(1);
    }

    mTitle1.setFont(mFont);
    mTitle2.setFont(mFont);
    mTitle1.setString("Fruit");
    mTitle2.setString("Ninja!");

    unsigned int fontSize = mBackground.getGlobalBounds().height/5;
    mTitle1.setCharacterSize(fontSize);
    mTitle2.setCharacterSize(fontSize);

    mTitle1.setScale(200/size.x, 200/size.y);
    mTitle2.setScale(200/size.x, 200/size.y);

    mTitle1.setPosition(mPosition.x, mPosition.y-130);
    mTitle2.setPosition(mPosition.x+60, mPosition.y-80);

    mTextColor = sf::Color::White;
    mTitle1.setFillColor(mTextColor);
    mTitle2.setFillColor(mTextColor);

    Button temp1("Start", {550,250}, {154,55});
    Button temp2("Exit", {550, 340}, {154,55});

    mStart = temp1;
    mExit = temp2;
    mStart.fixFiles();
    mExit.fixFiles();

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

void MainMenu::fixFiles()
{
    mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png");
    if(!mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png"))
    {
        std::cout<< "Cannot open background texture";
        exit(1);
    }
    mBackground.setTexture(mBackTexture);

    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        std::cout<< "Issue loading font, main menu\n";
        exit(1);
    }

    mTitle1.setFont(mFont);
    mTitle2.setFont(mFont);

    mStart.fixFiles();
    mExit.fixFiles();
}