#include "pause.h"


/*    public:
    Pause();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    bool isPaused;
    Button mPause;
    Button mResume;
    Button mExit;
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