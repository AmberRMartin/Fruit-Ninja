/**
 * @file main.cpp
 * @author Amber Martin, Nicholas Cicala, Matthew Barber
 * @brief Create and play a small turn-based rpg called Fruit Ninja
 * @version 0.1
 * @date 2024-11-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */


// This the main.cpp file
// Add #includes as you see fit

#include "mainMenu.h"
#include "button.h"
#include "game.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900,500), "Fruit Ninja!");
    Game game;
    MainMenu mainMenu({450, 250},{500,500}); //Position, size
    Button mStart("Start", {550,250}, {154,55});
    Button mExit("Exit", {550, 340}, {154,55});


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            window.clear();

//Main menu
            if(game.startmenu == false) //Do not do a while loop here. You WILL get trapped
            {

                window.draw(mainMenu);
                window.draw(mStart);
                window.draw(mExit);

                if(mStart.clicked(event,window))
                {
                    game.startmenu = true;
                }
                else if(mExit.clicked(event,window))
                {
                    window.close();
                }
            }
        }
//Note: putting window.clear(); over here at the bottom makes the images flash. 
//Leave window.close() where it is unless you can fix it
        window.display();
    }

}