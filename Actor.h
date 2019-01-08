#pragma once

#include "SFML/Graphics/Sprite.hpp"

//base class for all custom classes, has a rectangle shape included so that this class can be used
//in collision checks
class Actor : public sf::Sprite
{
public:
	Actor();
	virtual ~Actor() = 0;
	
	sf::FloatRect getRect() const;

protected:
	sf::FloatRect m_box;
	int m_spriteHeight;
	int m_spriteWidth;
};

