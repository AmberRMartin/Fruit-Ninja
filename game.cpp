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


void Game::draw(sf::RenderTarget& target,sf::RenderStates states) const
{

}



//Misc. Functions

// void StartMenu(Game &game, MainMenu &menu,sf::RenderWindow &window)
// {

// //Events go here
//     sf::Event event; 

//     menu.handleInput(event, window);

// //Actual draw stuff
//     window.clear();
//     menu.resize(window);
//     window.draw(menu);
// //     window.draw(menu.mStart); Segmentation faults for unknown reasons
// //     window.draw(menu.mExit);
//     window.display();

// //ONLY when start button is hit, change game mainmenu to true

// }
   

    

