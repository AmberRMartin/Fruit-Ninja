/**
 * @file action.h
 * @author Nicholas Cicala
 * @brief Abilities Declaration File
 * @date 2024-10-23
 * 
 */

#ifndef ACTION_HPP
#define ACTION_HPP

//#include "game.h"
#include "stats.h"
#include <vector>
#include <string>

class Action
{
public:
    Action();
    Action(double d, bool t, int m);
    double getDamage() const {return mDamageMult;}
    double getCost() const {return mCost;}
    double getTarget() const {return mTargetsMonster;}
    friend Stats;
protected:
    double mDamageMult;
    bool mTargetsMonster;
    int mCost;
};

#endif