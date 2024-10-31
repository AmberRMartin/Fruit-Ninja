#include "mainMenu.h"

MainMenu::MainMenu()
{
/*
INITIALIZE ALL VARIABLES

TODO: INITIALIZE SPRITES
    sf::Sprite mBackground;
    Also buttons
    */

    mBackTexture.loadFromFile("/Sprites/Main_Menu_Idea.png");
    if(!mBackTexture.loadFromFile("/Sprites/Main_Menu_Idea.png"))
    {
        std::cout<< "Cannot open background texture";
    }

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
    

}


void MainMenu::render()
{
    while(mWindow.isOpen())
    {
        sf::Event event;

        //Close if exit button is hit
        if (event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
    

/*
Render buttons
Render locations of Text
Render background image
Update buttons during the drawing process

*/



    }

}


void MainMenu::handleInput()
{
/*
Get locations of buttons and check for clicks within the buttons
for start button click- left click, exit main menu, go to level 1 of game

*/
}



/*
Button class for the main menu goes here
*/
Button::Button():Button("Error!",{100,100},{100,100})
{
//Default constructor. If this button pops up then I did something Very Wrong:tm:

}

Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size)
{
    /*
    sf::Sprite mButton;
    sf::Text mText;
    sf::Texture mTexture;
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    sf::Font mFont;
    */


    mTexture.loadFromFile("Sprites/button.png");
    if (!mTexture.loadFromFile("Sprites/button.png"))
    {
        std::cout<< "Cannot load button texture\n";
        exit(1);
    }
    mButton.setTexture(mTexture);


    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
//Scale goes here
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
                //Do something to go to game.
            }
            else if (mText.getString() == "Exit")
            {
                //Close game
            }
            else
            {
                //Exception
            }
        }
    }



}
