
#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include <SFML/Graphics.hpp>
#include "button.h"

class BattleScreen: public sf::Drawable //public other stuff
{
    public:
        BattleScreen();
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    protected:
        sf::Font font;
        sf::Text MonsterAtk;

        sf::Vector2f mPosition;

        Button Attack;
        Button Skill;
        Button Skill1;
        Button Skill2;

        sf::Sprite Background;
        sf::Sprite SkillBackground;
        sf::Sprite ButtonBackground;

        sf::Sprite MonsterN; //normal
        sf::Sprite MonsterA; //attacking
        sf::Sprite MonsterD; //damaged

        sf::Sprite PlayerN;
        sf::Sprite PlayerA;
        sf::Sprite PlayerD;

        sf::Text PHpTxt; //player health text
        sf::Text PManaTxt; //player mana text
};


#endif

/*
TO DO LIST:

[] Create sprite
[] Implement in battle variable
[] Use a temp button on screen to test battle
[] Have battle screen only show, use inventory as test
[] Implement attack and skill buttons
[] if Skill, make a mini screen with buttons for the skills as well
[] Figure out how frame rates work

*/