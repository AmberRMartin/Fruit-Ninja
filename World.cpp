/**
 * @file World.cpp
 * @author Matthew Barber
 * @brief definition for World Functions
 * @date 2024-11-05
 */
 #include "World.h"
 void World::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    target.draw(mObject,states);
 }