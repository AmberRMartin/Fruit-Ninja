/**
 * @file stats.h
 * @author Nicholas Cicala
 * @brief Stats Declaration File
 * @date 2024-10-23
 * 
 */

#ifndef STATS_HPP
#define STATS_HPP

//#include "game.h"
#include <string>

class Stats{
public:
    Stats();
    Stats(int h, int a, int l, int m, std::string n);
    int getHP() const {return mHP;}
    int getMaxHP() const {return mMaxHP;}
    int getMana() const {return mMana;}
    int getMaxMana() const {return mMaxMana;}
    int getATK() const {return mATK;}
    int getLevel() const {return mLevel;} //Fake Levels, not influencing stats
    void fullHeal() {mHP = mMaxHP;}
    void fullMP() {mMana = mMaxMana;}
    std::string getName() const {return mName;}
    void isAttacked(int damage);
    void spendMP(int cost);
    void levelUp();
protected:
    int mHP;
    int mMaxHP;
    int mATK;
    int mLevel;
    int mMana;
    int mMaxMana;
    std::string mName;
    
    void reduceMana(int cost);
};

#endif