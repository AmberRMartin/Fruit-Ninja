
/*
Game.h and Game.cpp are designed
to be edited as needed for various tasks
Good luck guys!

*/
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    public:
    Game();
    ~Game(){};
    void render();
    bool isDone() const;
    void MainMenu();
    void update();

    protected:
    sf::RenderWindow mWindow;
    bool mIsDone;
    sf::Font mFont;
};


#endif