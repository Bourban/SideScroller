#pragma once
#include "Actor.h"
#include "SFML\System\Clock.hpp"

//Base class of Player and Enemy for use with command method calls

class Character :
	public Actor
{
public:
	Character();
	~Character();

	void updateTime(sf::Time &time);

	void moveLeft();
	void moveRight();

	void attack();

protected:
	sf::Time elapsed;
};

