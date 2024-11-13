/**
 * @file Entity.h
 * @author Matthew Barber
 * @brief declaration for derived Entity class
 * @date 2024-11-06
 */
#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "World.h"
using namespace std;

class Entity :World {
    public:
    Entity(int rectL,int rectT, int Wid, int Len, int arrayPos[], sf::Vector2f pos,
           bool Player, int cLevel);
    virtual void draw();

    protected:
        int mLevel;
        int mArrayPos[2];
        bool mIsPlayer;
};

#endif