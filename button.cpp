#include "button.h"


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
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    mButton.setScale(size.x/(mTexture.getSize().x), size.y/(mTexture.getSize().y));

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
    mText.setPosition(mPosition.x, mPosition.y+10);

    mText.setFillColor(sf::Color::Black);

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
                std::cout<< "Start button clicked!\n";
            }
            else if (mText.getString() == "Exit")
            {
                std::cout<< "Exit button clicked!\n";
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
    target.draw(mText, states);
}