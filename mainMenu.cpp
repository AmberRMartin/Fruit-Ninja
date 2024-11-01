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

    mBackTexture.loadFromFile("/Sprites/Main_Menu_Idea.png");
    if(!mBackTexture.loadFromFile("/Sprites/Main_Menu_Idea.png"))
    {
        std::cout<< "Cannot open background texture";
    }
    mBackground.setTexture(mBackTexture);

//Set text font
    mTitle1.setFont(mFont);
    mTitle2.setFont(mFont);
    

//Set text words
    mTitle1.setString("Fruit");
    mTitle2.setString("Ninja!");
    

//set colors
    mTextColor = sf::Color::White;
    mTitle1.setColor(mTextColor);
    mTitle2.setColor(mTextColor);

//Position can stay at 0,0 since this takes the entire screen
//But I'll initialize it anyway
    mPosition = {0,0};
    
//Initialize the two buttons

// Button mExit;
    Button temp1("Start", {621, 523},{375,134});
    mStart = temp1;
    Button temp2("Exit", {767, 760},{375,134});
    mExit = temp2;

    mIsDone = false;
    
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













/**
 * @brief Default construct a new Button:: Button object
 * 
 */
Button::Button():Button("Error!",{100,100},{100,100})
{
//Default constructor. If this button pops up then I did something Very Wrong:tm:

}

/**
 * @brief Construct a new Button:: Button object
 * 
 * @param s Message on button
 * @param position Position on button
 * @param size Size of button
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size)
{
//Texture of buttons, custom.
    mTexture.loadFromFile("Sprites/button.png");
    if (!mTexture.loadFromFile("Sprites/button.png"))
    {
        std::cout<< "Cannot load button texture\n";
        exit(1);
    }
    mButton.setTexture(mTexture);



    sf::Vector2u imageSize=mTexture.getSize();


    mPosition = position;
    mButton.setPosition(mPosition.x,mPosition.y);

    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if (!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    { 
        exit(2);
    }

    mText.setFont(mFont);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setString(s);


    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);

    mBtnState = normal;
}





/**
 * @brief Checks for whether or not a button has been clicked
 * 
 * @param e Event, usually button click
 * @param window Window everything is being displayed on
 */
void Button::update(sf::Event& e, sf::RenderWindow& window)
{
   
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
    bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;

if (e.type == sf::Event::MouseButtonPressed)
    {
        if(mouseInButton)
        {
            if(mText.getString() == "Start")
            {
                //Unsure what I need to do here tbh, but exit mainmenu
            }
            else if (mText.getString() == "Exit")
            {
                window.close();
            }
            else
            {
                //Exception
            }
        }
    }
}


/**
 * @brief Draw function for buttons
 * 
 * @param target 
 * @param states 
 */
void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
}