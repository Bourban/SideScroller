#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	~Player();

private:
	sf::Time* elapsed;
};

