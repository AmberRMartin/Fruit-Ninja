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
#include <fstream>
using namespace std;

class World {
    public:
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    protected:
        sf::Sprite mObject;
        sf::Texture mTexture;
        sf::Text mText;
        sf::Font mFont;
        sf::Vector2f mPos;
};

#endif