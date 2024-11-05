/*

This the main.cpp file
Add #includes as you see fit

*/
#include <iostream>
#include "stats.h"

int main ()
{
    Stats stats;
    Stats stats2;
    std::cout << "Entity 1 - HP: " << stats.getHP() 
            << "/" << stats.getMaxHP() << " ATK: " 
            << stats.getATK() << " LV: " 
            << stats.getLevel() << std::endl;
    std::cout << "Entity 2 - HP: " << stats2.getHP() 
            << "/" << stats2.getMaxHP() << " ATK: " 
            << stats2.getATK() << " LV: " 
            << stats2.getLevel() << std::endl;

    stats.reduceHP(stats2.getATK());

    std::cout << "Entity 1 - HP: " << stats.getHP() 
            << "/" << stats.getMaxHP() << " ATK: " 
            << stats.getATK() << " LV: " 
            << stats.getLevel() << std::endl;

    stats2.levelUp();

    std::cout << "Entity 2 - HP: " << stats2.getHP() 
            << "/" << stats2.getMaxHP() << " ATK: " 
            << stats2.getATK() << " LV: " 
            << stats2.getLevel() << std::endl;

    stats.reduceHP(999);

    std::cout << "Entity 1 - HP: " << stats.getHP() 
            << "/" << stats.getMaxHP() << " ATK: " 
            << stats.getATK() << " LV: " 
            << stats.getLevel() << std::endl;
}