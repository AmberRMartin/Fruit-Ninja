#include "inventory.h"

Inventory::Inventory():Inventory({0,0}, {0,0})
{

}

Inventory::Inventory(sf::Vector2f position, sf::Vector2f size)
{
        /*
        Button Open;
        Button Close;
        sf::Sprite Menu;
        sf::Text LV;
        sf::Text HP;
        sf::Text ATK;
        sf::Text Sword;
        sf::Text Bandana;
    */
   //Button temp1{"Pause", {650,30},{77,27}};
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