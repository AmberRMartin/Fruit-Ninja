/**
 * @file stats.h
 * @author Nicholas Cicala
 * @brief Stats Declaration File
 * @date 2024-10-23
 * 
 */

#ifndef STATS_HPP
#define STATS_HPP

//No Game/Battle Class yet, not a child of it yet; Unsure if it should be a parent or child of Battle currently
class Stats{
public:
    Stats();
    Stats(int h, int a, int l);
    int getHP() const {return mHP;}
    int getMaxHP() const {return mMaxHP;}
    int getATK() const {return mATK;}
    int getLevel() const {return mLevel;} //Fake Levels, not influencing stats
    void reduceHP(int damage); //currently public for testing purposes
    void levelUp(); //currently public for testing purposes
protected:
    int mHP;
    int mMaxHP;
    int mATK;
    int mLevel;
    void fullHeal() {mHP = mMaxHP;} // full heal, may or may not add healing skills
};

#endif