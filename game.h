
/*
Game.h and Game.cpp are designed
to be edited as needed for various tasks
Good luck guys!

*/
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "mainMenu.h"
#include "button.h"


//Game class, add as needed, avoid subtracting 
class Game: public sf::Drawable
{
    public:
    Game();
    ~Game();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    bool isDone() const;
    void MainMenu();
    void update();
    bool startmenu;

    protected:
    bool mIsDone;
    sf::Font mFont;
};

//Functions for misc stuff go here

void StartMenu(Game &game, MainMenu &menu, sf::RenderWindow &window);

#endif