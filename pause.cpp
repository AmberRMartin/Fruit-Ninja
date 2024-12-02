/**
 * @file pause.cpp
 * @author Amber Martin
 * @brief Pause functions for drawing/update
 * @version 0.1
 * @date 2024-11-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "pause.h"

/**
 * @brief Construct a new Pause:: Pause object
 * 
 */
Pause::Pause()
{
    isPaused = false; 

    Button temp1{"Pause", {650,30},{77,27}};
    Button temp2{"Resume", {450,220},{154,55}};
    Button temp3{"Exit", {450,320}, {154,55}};

    mPause = temp1;
    mResume = temp2;
    mExit = temp3;
//It heavily dislikes copying buttons, so fix files and text

    mPause.fixFiles();
    mResume.fixFiles();
    mExit.fixFiles();
}


/**
 * @brief Draws the buttons n stuff for pause menu
 * 
 * @param target 
 * @param states 
 */
void Pause::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    if(!isPaused)
    {
        target.draw(mPause, states);
    }
    else
    {
        target.draw(mResume, states);
        target.draw(mExit, states);
    }
}


/**
 * @brief checks for button clicking and updates display
 * 
 * @param e 
 * @param window 
 */
void Pause::update(sf::Event& e, sf::RenderWindow& window)
{
    if(mPause.clicked(e, window))
    {
        isPaused = true;
    }
    else if(mResume.clicked(e, window))
    {
        isPaused = false;
    }
    else if (mExit.clicked(e, window))
    {
        window.close();
    }
}
