#include "game.h"

Game::Game() : mWindow(sf::VideoMode(1000,1000), "Fruit Ninja!")
{

    mIsDone = false;
    mFont.loadFromFile("Minecraftia-Regular.ttf");
    if(!mFont.loadFromFile("Minecraftia-Regular.ttf"))
    {
        exit(1);
    }
}

void Game::render()
{
    mWindow.clear(sf::Color::Black);
}