/**
 * @file battle.h
 * @author Nicholas Cicala
 * @brief Battle System Declaration File
 * @date 2024-10-23
 * 
 */

#ifndef BATTLE_HPP
#define BATTLE_HPP

//#include "game.h"
#include "stats.h"
#include "action.h"
#include <vector>
#include <string>

class Battle{
public:
    Battle();
    Battle(int n);
    ~Battle();
    void battleinstance(int numMonsters);
    void generateMonster(int hp, int a, int l, int m, std::string n);
    void battleLoop();
    void PlayerAction();
    void PlayerProcessAndCheck();
    void MonsterAction();
    void MonsterProcessAndCheck();
    void EndBattle();
    bool isInBattle;
protected:
    std::vector<Stats> mMonsters;
    std::vector<Action> mPlayerAbilities;
    Action basicAttack;
    Stats player;
    Stats* mPlayer;
    Stats* target;
    Action* abilityptr;
    double mDamage;
    int mAction;
};

#endif