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
}

/**
 * @brief Constructor with parameters to add specific details
 * 
 * @param h Generated Health
 * @param a Generated Attack
 * @param l Generated Level
 */
Stats::Stats(int h, int a, int l)
{
    mMaxHP = h;
    fullHeal();
    mATK = a;
    mLevel = l;
}

/**
 * @brief Reduction in HP via attack or some other source, 
 *        HP locked at 0 if damage is greater than HP.
 * 
 * @param damage HP to remove
 */
void Stats::reduceHP(int damage)
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
 * @brief Increases stats, Not final numbers
 * 
 */
void Stats::levelUp()
{
    mMaxHP = mMaxHP + 5;
    fullHeal();
    mATK = mATK + 3;
    mLevel++;
}