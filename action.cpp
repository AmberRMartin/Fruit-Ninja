/**
 * @file action.cpp
 * @author Nicholas Cicala
 * @brief Abilities Implementation File
 * @date 2024-10-23
 * 
 */

#include "battle.h"
#include "stats.h"
#include <iostream>

/**
 * @brief Default Constructor for Action
 * 
 */
Action::Action()
{
    mDamageMult = 1;
    mTargetsMonster = true;
    mCost = 0;
}

/**
 * @brief Constructor with parameters to add specific details
 * 
 * @param d MULTIPLIER of damage, not full value.
 * @param t true targets opposite side (i.e. Attack Abilities), false targets same side (i.e. Heal Abilities)
 * @param m Cost in Mana
 * @param n Name of ability
 */
Action::Action(double d, bool t, int m)
{
    mDamageMult = d;
    mTargetsMonster = t;
    mCost = m;
}