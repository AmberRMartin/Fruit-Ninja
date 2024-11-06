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

class Entity : Public World {
    public:
    Entity(int rectCord, int Wid, int Len, int arrayPos[], sf::Vector2f pos
           bool Player, int cLevel,ifstream& textF,ifstream& textureF);
    virtual void draw();

    protected:
        int mLevel;
        int mArrayPos[2];
        bool mIsPlayer;
}

#endif