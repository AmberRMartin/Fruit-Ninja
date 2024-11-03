/*
Use this as a peusdo main
branch: MainMenu

compile command: g++ -std=c++11 menu.cpp button.cpp game.cpp mainMenu.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system




TODO LIST:
Main menu Sprite
    -background
    -buttons
    -font (free online)

Menu functions
    -Start game
        -When game started, cutscene before entering map
    -Exit game
    -Optional: Easter egg, click on a tree and a monster peeks out?


*/

#include "mainMenu.h"
#include "game.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500,500), "Fruit Ninja!");
    Game game;
    MainMenu menu1({250, 250},{500,500}); //Position, size
    Button mStart("Start", {350,250}, {154,55});
    Button mExit("Exit", {350, 340}, {154,55});


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(game.startmenu == false) //Do not do a while loop here. You WILL get trapped
            {
                window.clear();
                window.draw(menu1);
                window.draw(mStart);
                window.draw(mExit);

                mStart.update(event,window);
                mExit.update(event,window);
            }

        }
        window.display();
    }

/*

//Events go here
    sf::Event event; 

    menu.handleInput(event, window);

//Actual draw stuff
    window.clear();
    menu.resize(window);
    window.draw(menu);
//     window.draw(menu.mStart); Segmentation faults for unknown reasons
//     window.draw(menu.mExit);
    window.display();

//ONLY when start button is hit, change game mainmenu to true

}*/

    std::cout<< "Successfully exited main menu!\n";
}