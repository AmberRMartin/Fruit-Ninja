/**
 * @file World.h
 * @author Matthew Barber
 * @brief Declaration for World Abstract Class
 * @date 2024-11-05
 */
#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
enum states {norm};

class World{
    protected:
        sf::Sprite mObject;
        sf::Texture mTexture;
        sf::Text mText;
        sf::Font mFont;
        sf::Vector2f mPosition;

};

#endif