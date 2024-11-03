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
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Fruit Ninja!");
    Game game;
    MainMenu menu1;

    while(window.isOpen())
    {
        while(game.startmenu == false)
        {
            StartMenu(game, menu1, window);
        }
    }

    std::cout<< "Successfully exited main menu!\n";
}