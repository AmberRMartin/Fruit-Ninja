/**
 * @file battle.h
 * @author Nicholas Cicala
 * @brief Battle System Declaration File
 * @date 2024-10-23
 * 
 */

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "stats.h"
#include "action.h"
#include "battleScreen.h"
#include <vector>
#include <string>

class Battle : public BattleScreen{
public:
    Battle();
    ~Battle();
    void battleinstance();
    void battleLoop();
    void PlayerAction(sf::Event& e, sf::RenderWindow& window);
    void PlayerProcessAndCheck();
    void MonsterAction();
    void MonsterProcessAndCheck();
    void EndBattle();
    bool isInBattle;
protected:
    Stats mMonster;
    std::vector<Action> mPlayerAbilities;
    Action basicAttack;
    Stats player;
    Stats* mPlayer;
    Stats* target;
    Action* abilityptr;
    double mDamage;
    int mAction;
    friend class Game;
};

#endif