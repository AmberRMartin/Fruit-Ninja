#include "game.h"

Game::Game() : mWindow(sf::VideoMode(500,500), "Fruit Ninja!")
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