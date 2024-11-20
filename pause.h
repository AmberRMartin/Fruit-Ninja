#ifndef PAUSE_H
#define PAUSE_H

#include "button.h"
#include <SFML/Graphics.hpp>

class Pause: public sf::Drawable//, public Button
{
    public:
    Pause();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    bool isPaused;
    void update(sf::Event& e, sf::RenderWindow& window);

    private:
    Button mPause;
    Button mResume;
    Button mExit;
    sf::RectangleShape mBack;

};


#endif

/*
After start menu
Put TWO buttons in the top right of the screen
one says "PAUSE"
the other says "INVENTORY"
This file is for PAUSE ONLY
It is to the RIGHT of the inventory button

What needs to happen for pause?

[] Create a button that appears in the top right corner that says pause
    -When clicked, brings up two buttons in center of screen
    -Player cannot move during this

[] Buttons say "START" and "EXIT"
    -Can reuse code from main menu buttons

[] Implement into main


*/