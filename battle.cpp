/**
 * @file battle.cpp
 * @author Nicholas Cicala
 * @brief Battle System Implementation File
 * @date 2024-10-23
 * 
 */

#include "battle.h"
#include "stats.h"
#include <iostream>

Battle::Battle() 
{
    isInBattle = true;
    battleinstance(1);
    battleLoop();
}

Battle::Battle(int n) 
{
    isInBattle = true;
    battleinstance(n);
    battleLoop();
}

Battle::~Battle()
{
    mPlayer = nullptr;
    target = nullptr;
    abilityptr = nullptr;
}

void Battle::battleinstance(int numMonsters)
{
    Action strongAttack(1.5, true, 5, "Strong Attack");
    Action heal(2, false, 10, "Meditation");
    mPlayerAbilities.push_back(strongAttack);
    mPlayerAbilities.push_back(heal);
    mPlayer = &player;
    for (int i = 0; i < numMonsters; i++)
    {
        generateMonster(30,5,1,0,"test");
    }
}

void Battle::generateMonster(int hp, int a, int l, int m, std::string n)
{
    Stats monster(hp,a,l,m,n);
    mMonsters.push_back(monster);
}

void Battle::battleLoop()
{
    while (isInBattle)
    {
        std::cout<<"Player HP: " << mPlayer->getHP() << " MP: " << mPlayer->getMana() << " MP: " << mPlayer->getATK() << std::endl;
        for (size_t i = 0; i < mMonsters.size(); i++)
        {
            std::cout<<"monster " << i << " HP: " << mMonsters[i].getHP() << std::endl;
        }
        
        PlayerAction();
        if (isInBattle == false)
            break;
        MonsterAction(); 
        if (isInBattle == false)
            break;       
    }
    EndBattle();
}

void Battle::PlayerAction()
{
    try
    {
        int mAction;
        //2a. Normal Attack or Abilities - abilities take 1 turn to cool down
        std::cout<<"Enter an action with number; 1=normal attack, 2=ability: ";
        std::cin>>mAction;
        
        if (mAction == 1)
        {
            abilityptr = &basicAttack;   
        }
        else if (mAction == 2)
        {
            std::cout<<"Which ability would you like to use? 1=strong attack, 2=heal: ";
            for (size_t i = 0; i < mPlayerAbilities.size(); i++)
            {
                std::cout << i << " = " << mPlayerAbilities[i].getName() << std::endl;
            }
            
            std::cin>>mAction;
            abilityptr = &mPlayerAbilities[mAction];
            if (mPlayer->getMana() < abilityptr->getCost())
            {
                {throw;}
            }            
        }
        if (abilityptr->getDamage() > 0)
        {
            std::cout<<"Which monster would you like to target?";
            for (size_t i = 0; i < mMonsters.size(); i++)
            {
                std::cout << i << " = " << mMonsters[i].getName() << std::endl;
            }
            std::cin>>mAction;
            target = &mMonsters[mAction];
        }
        else
        {throw;}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    PlayerProcessAndCheck();
}

void Battle::PlayerProcessAndCheck()
{
    //3. Process and attack monster
    mDamage = static_cast<int>(mPlayer->getATK() * abilityptr->getDamage());
    mPlayer->spendMP(abilityptr->getCost());
    if (abilityptr->getTarget())
    {
        target->isAttacked(mDamage);
        std::cout << "Monster has been attacked for " << mDamage << " damage!\n";
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
        std::cout << "Player has healed " << mDamage << " health!\n";
    }

    if(target->getHP() == 0)
    {
        mMonsters.erase(mMonsters.begin()+mAction);
        target = nullptr;
    }
    if (mMonsters.size() == 0)
    {
        isInBattle = false;
    }
}

void Battle::MonsterAction()
{
    for (size_t i = 0; i < mMonsters.size(); i++)
    {
        target = &mMonsters[i];
        mDamage = target->getATK();
        mPlayer->isAttacked(mDamage);
        std::cout << "Player has been attacked for " << mDamage << " damage!\n";
        //4a. Check if player is ded - if true go to 5, else go back to 2
        if (mPlayer->getHP() == 0)
        {
            isInBattle = false;
            break;
        }
    }    
}

void Battle::EndBattle()
{
    if (mMonsters.size() == 0)
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