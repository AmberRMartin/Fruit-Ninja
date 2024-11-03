#include "game.h"
#include "mainMenu.h"
#include "button.h"


//Game class
Game::Game()
{

    mIsDone = false;
    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        exit(1);
    }
    startmenu = false;
}

Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target,sf::RenderStates states) const
{

}

//Misc. Functions

void StartMenu(Game &game, MainMenu &menu,sf::RenderWindow &window)
{


    sf::Event event;
    if(event.type == sf::Event::Closed)
    {
        window.close();
    }

//Events go here
    menu.handleInput(event, window);

//Actual draw stuff
    window.clear();
    window.draw(menu);
    // window.draw(menu.mStart);
    // window.draw(menu.mExit);
    window.display();

//ONLY when start button is hit, change game mainmenu to true

}
   

    

