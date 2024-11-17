#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Graphics.hpp>
#include "stats.h"
#include "button.h"
class Inventory: public sf::Drawable, public Stats
{
    public:
        Inventory();
        Inventory(sf::Vector2f position, sf::Vector2f size);
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        void update(sf::Event& e, sf::RenderWindow& window);

        bool isOpen;

    private:
        Button Open;
        Button Close;
        sf::Sprite Menu;
        sf::Texture menuTexture;
        sf::Vector2f mPosition; 
        sf::Text LV;
        sf::Text HP;
        sf::Text ATK;
        sf::Text Sword;
        sf::Text HeadTie;
        sf::Font mFont;
};

#endif

/*
Inventory game plan:

After start menu
Put TWO buttons in the top right of the screen
one says "PAUSE"
the other says "INVENTORY"
This file is for INVENTORY ONLY
It is to the LEFT of the pause button

What needs to happen for inventory?
[] Create a button that says inventory in the main screen
        -Have the button be a part of the inventory class
        -When clicked, pull up a screen that's about 2/3s of the map screen. Square.
        -Have map be visible underneath, because that's fun!
[] Display various stats, pull number from stats class made by nick
        -Inventory class both child of drawable and of stats?
[] Display "items"
        -Two items
        -Sword
        -Bandana
        -Goes above the stats
[] Have the square split in two, one side for items, other with a higher resolution image of ninja
        -Have a blank rectangle underneath
        -When sword/bandana is clicked, display a text in that rectangle
        -It's a brief description of what the item is
[] Implement into main

*/