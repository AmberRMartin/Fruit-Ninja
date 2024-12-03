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
    Action(double d, bool t, int m, std::string n);
    double getDamage() const {return mDamageMult;} // for display stuff
    double getCost() const {return mCost;} // for display stuff
    double getTarget() const {return mTargetsMonster;} // for display stuff
    std::string getName() const {return mName;}
    friend Stats;
protected:
    double mDamageMult;
    bool mTargetsMonster;
    int mCost;
    std::string mName;
};

#endif