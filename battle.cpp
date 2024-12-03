/**
 * @file battle.cpp
 * @author Nicholas Cicala
 * @brief Battle System Implementation File
 * @date 2024-10-23
 * 
 */

#include "game.h"
#include "battle.h"
#include "stats.h"
#include <iostream>
/**
 * @brief Initiate new battle
 * 
 */
Battle::Battle() 
{
    isInBattle = true;
    battleinstance();
    battleLoop();
}
/**
 * @brief Deconstructor for Battle
 * 
 */
Battle::~Battle()
{
    mPlayer = nullptr;
    target = nullptr;
    abilityptr = nullptr;
}
/**
 * @brief Setup Abilities + Stats
 */
void Battle::battleinstance()
{
    Action strongAttack(1.5, true, 5);
    Action heal(2, false, 10);
    mPlayerAbilities.push_back(strongAttack);
    mPlayerAbilities.push_back(heal);
    //mPlayer = stats;
}

/**
 * @brief The Battle Loop
 * 
 */
void Battle::battleLoop()
{
    while (isInBattle)
    {        
        PlayerAction();
        if (isInBattle == false)
            break;
        MonsterAction(); 
        if (isInBattle == false)
            break;       
    }
    EndBattle();
}

/**
 * @brief For the Player to do an action
 * 
 */
void Battle::PlayerAction()
{
    sf::Event event;
    //2a. Normal Attack or Abilities
    
    PlayerProcessAndCheck();
}

/**
 * @brief Processes the player action
 * 
 */
void Battle::PlayerProcessAndCheck()
{
    //3. Process and attack monster
    mDamage = static_cast<int>(mPlayer->getATK() * abilityptr->getDamage());
    mPlayer->spendMP(abilityptr->getCost());
    if (abilityptr->getTarget())
    {
        mMonster.isAttacked(mDamage);
    }
    else
    {
        if (mPlayer->getMaxHP() > mPlayer->getHP() + mDamage)
        {
            mPlayer->fullHeal();
        }
        else
        {
            mPlayer->isAttacked(mDamage);
        }
    }

    if(mMonster.getHP() == 0)
    {
        isInBattle = false;
    }
}

/**
 * @brief Automatically processes monster action
 * 
 */
void Battle::MonsterAction()
{
    
    mDamage = mMonster.getATK();
    mPlayer->isAttacked(mDamage);
    //4a. Check if player is ded - if true go to 5, else go back to 2
    if (mPlayer->getHP() == 0)
    {
        isInBattle = false;
    }  
}

/**
 * @brief End of the battle
 * 
 */
void Battle::EndBattle()
{
    if (mMonster.getHP() == 0)
    {
        std::cout << "You won!";
        mPlayer->levelUp();
    }
    
    //5b. else Game over
    else
    {
        std::cout << "Game Over!";
    }
}