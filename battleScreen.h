/**
 * @file battleScreen.h
 * @author Amber Martin
 * @brief Battle screen visuals
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include <SFML/Graphics.hpp>
#include "button.h"
#include "stats.h"

class BattleScreen: public sf::Drawable //public other stuff
{
    public:
        BattleScreen();
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        void update(sf::Event& e, sf::RenderWindow& window);
        void updateStats(Stats &stats);
        void ChangeMonster(int num);

        void PlayerAction(sf::Event& e, sf::RenderWindow& window);

    protected:

        bool SkillMenu;
        sf::Font font;

        sf::Vector2f BackgroundPosition;
        sf::Vector2f MonsterPosition;
        sf::Vector2f PlayerPosition;

        Button Attack;
        Button Skill;
        Button Heal;
        Button SkillAtk;
        Button ReturnSkill;

        sf::Sprite Background;

        sf::Sprite MonsterN; //normal
        sf::Sprite MonsterA; //attacking
        sf::Sprite MonsterD; //damaged

        sf::Sprite PlayerN;
        sf::Sprite PlayerA;
        sf::Sprite PlayerD;

        sf::Texture backTexture;
        sf::Texture skillBackTexture;
        sf::Texture Monsters;
        sf::Texture Players;

        sf::Text PHpTxt; //player health text
        sf::Text PManaTxt; //player mana text
};


#endif
