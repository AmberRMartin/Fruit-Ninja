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
/*
MainMenu mainMenu({450, 250},{500,500}); //Position, size
Button mStart("Start", {550,250}, {154,55});
*/
//Button(std::string s, sf::Vector2f position, sf::Vector2f size); constructor

    Button temp1{"Pause", {500,30},{77,27}};
    Button temp2{"Resume", {450,220},{154,55}};
    Button temp3{"Exit", {450,320}, {154,55}};

    mPause = temp1;
    mResume = temp2;
    mExit = temp3;
//It heavily dislikes copying buttons, so fix files and text
//Which I added a whole new function for and I'm praying it works
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