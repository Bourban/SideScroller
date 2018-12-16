#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

//base class for all custom classes, has a rectangle shape included so that this class can be used
//in collision checks
class Actor : public sf::Sprite
{
public:
	Actor();
	virtual ~Actor() = 0;
	
	sf::RectangleShape getRect();

private:
	sf::RectangleShape box;

};

