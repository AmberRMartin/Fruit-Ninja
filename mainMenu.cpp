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
MainMenu::MainMenu()
{

    mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png");
    if(!mBackTexture.loadFromFile("Sprites/Main_Menu_Idea.png"))
    {
        std::cout<< "Cannot open background texture";
    }
    mBackground.setTexture(mBackTexture);

//Set text font

    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        std::cout<< "Cannot load font, main menu\n";
        exit(1);
    }
    mTitle1.setFont(mFont);
    mTitle2.setFont(mFont);
    

//Set text words
    mTitle1.setString("Fruit");
    mTitle2.setString("Ninja!");
    

//set colors
    mTextColor = sf::Color::White;
    mTitle1.setOutlineColor(mTextColor);
    mTitle2.setOutlineColor(mTextColor);
    

//Position can stay at 0,0 since this takes the entire screen
//But I'll initialize it anyway
    mPosition = {0,0};
    
//Initialize the two buttons

// Button mExit;
    // Button temp1("Start", {621, 523},{375,134});
    // mStart = temp1;
    // Button temp2("Exit", {767, 760},{375,134});
    // mExit = temp2;

   // mIsDone = false;
    
}

MainMenu::~MainMenu()
{

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
}



/**
 * @brief Takes the buttons inside main menu, checks for events
 * 
 * @param e 
 * @param window 
 */
void MainMenu::handleInput(sf::Event& e, sf::RenderWindow& window)
{
    mStart.update(e, window);
    mExit.update(e, window);
}




