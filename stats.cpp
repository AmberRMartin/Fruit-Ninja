/**
 * @file stats.cpp
 * @author Nicholas Cicala
 * @brief Stats Implementation File
 * @date 2024-10-23
 * 
 */

#include "stats.h"
#include <iostream>

/**
 * @brief Default Constructor for new Entity Stats
 * 
 */
Stats::Stats()
{
    mMaxHP = 20;
    fullHeal();
    mATK = 5;
    mLevel = 1;
    mMaxMana = 10;
    fullMP();
    mName = "";
}

/**
 * @brief Constructor with parameters to add specific details
 * 
 * @param h Generated Health
 * @param a Generated Attack
 * @param l Generated Level
 * @param m Generated Mana
 * @param n Name
 */
Stats::Stats(int h, int a, int l, int m, std::string n)
{
    mMaxHP = h;
    fullHeal();
    mATK = a;
    mLevel = l;
    mMaxMana = m;
    fullMP();
    mName = n;
}

/**
 * @brief Reduction in HP via attack or some other source, 
 *        HP locked at 0 if damage is greater than HP.
 * 
 * @param damage HP to remove
 */
void Stats::isAttacked(int damage)
{
    if (mHP < damage)
    {
        mHP = 0;
    }
    else
    {
        mHP -= damage;
    }
}

/**
 * @brief Reduction in MP via using abilities
 * 
 * @param cost MP to remove
 */
void Stats::spendMP(int cost)
{
    mMana -= cost;
}

/**
 * @brief Increases stats, Not final numbers
 * 
 */
void Stats::levelUp()
{
    mMaxHP = mMaxHP + 6;
    fullHeal();
    mATK = mATK + 4;
    mMaxMana = mMaxMana + 3;
    fullMP();
    mLevel++;
}