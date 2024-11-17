#include "inventory.h"

Inventory::Inventory():Inventory({450,250}, {400,400})
{
//Inventory inventoryMenu({450,250}, {400,400});
}

Inventory::Inventory(sf::Vector2f position, sf::Vector2f size)
{

    isOpen = false;

//Buttons
    Button temp1{"Pockets", {560,30},{77,27}};
    Open = temp1;
    Open.fixFiles();

    Button temp2{"Close", {610,65}, {77,27}};
    Close = temp2;
    Close.fixFiles();

    menuTexture.loadFromFile("Sprites/Fruit_Ninja_inventory_menu.png");
    if(!menuTexture.loadFromFile("Sprites/Fruit_Ninja_inventory_menu.png"))
    {
        std::cout<< "Cannot open background texture";
    }
    Menu.setTexture(menuTexture);

//Size stuff
    sf::Vector2u imageSize= menuTexture.getSize();
    Menu.setScale(size.x/(menuTexture.getSize().x),size.y/(menuTexture.getSize().y));

//Positioning
    Menu.setOrigin(imageSize.x/2, imageSize.y/2); //For centering
    mPosition = position;
    Menu.setPosition(mPosition.x, mPosition.y);

    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if (!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    { 
        exit(2);
    }
    LV.setFont(mFont);
    HP.setFont(mFont);
    ATK.setFont(mFont);
    Sword.setFont(mFont);
    HeadTie.setFont(mFont);

    unsigned int fontSize = Menu.getGlobalBounds().height/17;
    LV.setCharacterSize(fontSize);
    HP.setCharacterSize(fontSize);
    ATK.setCharacterSize(fontSize);
    Sword.setCharacterSize(fontSize);
    HeadTie.setCharacterSize(fontSize);


    LV.setString("LV   " + std::to_string(getLevel()));
    HP.setString("HP   " + std::to_string(getHP()));
    ATK.setString("ATK  " + std::to_string(getATK()));
    Sword.setString("Sword");
    HeadTie.setString("Tie");

    LV.setOrigin(0, LV.getGlobalBounds().height/2);
    HP.setOrigin(0, HP.getGlobalBounds().height/2);
    ATK.setOrigin(0, ATK.getGlobalBounds().height/2);
    Sword.setOrigin(0, Sword.getGlobalBounds().height/2);
    HeadTie.setOrigin(0, HeadTie.getGlobalBounds().height/2);

    LV.setPosition(270, 270);
    HP.setPosition(270, 350);
    ATK.setPosition(260, 430);
    Sword.setPosition(320, 110);
    HeadTie.setPosition(320,190);

    LV.setFillColor(sf::Color::Black);
    HP.setFillColor(sf::Color::Black);
    ATK.setFillColor(sf::Color::Black);
    Sword.setFillColor(sf::Color::Black);
    HeadTie.setFillColor(sf::Color::Black);


/*      sf::Text LV;
        sf::Text HP;
        sf::Text ATK;
        sf::Text Sword;
        sf::Text Bandana;
        int getMaxHP() const {return mMaxHP;}
        int getATK() const {return mATK;}
        int getLevel() const {return mLevel;} //Fake Levels, not influencing stats
        
*/


}

void Inventory::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    if(isOpen == false)
    {
        target.draw(Open, states);
    }
    else
    {
        target.draw(Menu, states);
        target.draw(Close, states);
        target.draw(Sword, states);
        target.draw(HeadTie, states);
        target.draw(LV, states);
        target.draw(HP, states);
        target.draw(ATK, states);
    }
}

void Inventory::update(sf::Event& e, sf::RenderWindow& window)
{
    if(Open.clicked(e, window))
    {
        isOpen = true;
    }
    else if(Close.clicked(e, window))
    {
        isOpen = false;
    }

}