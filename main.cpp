/**
 * @file main.cpp
 * @author Amber Martin, Nicholas Cicala, Matthew Barber
 * @brief Create and play a small turn-based rpg called Fruit Ninja
 * @version 0.1
 * @date 2024-11-03
 * @compile  g++ -std=c++11 *.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 * @copyright Copyright (c) 2024
 * 
 */


// // This the main.cpp file
// // Add #includes as you see fit
#include "game.h"
#include "Zone.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900,500), "Fruit Ninja!");
    Game game;

//delete when no longer needed
    Button temp{"Battle", {100,100}, {154,55}};
    Zone Zone1(0,0,"Yes", {450,250},{500,500}, sf::Color::Red);
    window.setKeyRepeatEnabled(false);

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

                window.draw(game.mainMenu);
                window.draw(game.mainMenu.mStart);
                window.draw(game.mainMenu.mExit);

                if(game.mainMenu.mStart.clicked(event,window))
                {
                    game.startmenu = true;
                }
                else if(game.mainMenu.mExit.clicked(event,window))
                {
                    window.close();
                }
            }

//Map screen
            else if (game.pauseMenu.isPaused == false && game.inventoryMenu.isOpen == false && game.inBattle == false)
            {
                window.draw(Zone1);
/*
Note for Matthew: This displays both pause and inventory button on screen.
This is the only section where the player is supposed to be able to move around
as the other two else if statements have one eof those menus open
You may delete this message whenever you please
*/
                window.draw(game.pauseMenu);
                game.pauseMenu.update(event, window);
                window.draw(game.inventoryMenu);
                game.inventoryMenu.update(event, window);
                game.inBattle = Zone1.update(event,window);

//TEMPORARY: for nick to activate battle mode 
window.draw(temp);
if(temp.clicked(event, window))
{
    game.inBattle = true;
}
            }
//Pause screen
            else if (game.pauseMenu.isPaused == true && game.inventoryMenu.isOpen == false)
            {
                window.draw(game.pauseMenu);
                game.pauseMenu.update(event, window);
            }

//Inventory screen
            else if (game.pauseMenu.isPaused == false && game.inventoryMenu.isOpen == true)
            {

                window.draw(game.inventoryMenu);
                game.inventoryMenu.update(event, window);
            }
//Battle screen
            else if (game.inBattle == true)
            {
                window.draw(game.battleScreen);
                game.battleScreen.update(event, window);
            }
        }


//Note: putting window.clear(); over here at the bottom makes the images flash. 
//Leave window.close() where it is unless you can fix it
        window.display();
    }

}