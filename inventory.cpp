#include "inventory.h"

Inventory::Inventory()
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

   Button temp1{"Pockets", {560,30},{77,27}};
   Open = temp1;
   Open.fixFiles();

   Button temp2{"Close", {500,250}, {107,57}};
   Close = temp2;
   Close.fixFiles();
}

void Inventory::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    if(isOpen == false)
    {
        target.draw(Open, states);
    }
    else
    {
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