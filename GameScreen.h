#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"
class GameScreen :
	public Screen
{
public:

	virtual int run(sf::RenderWindow &window);

	GameScreen();
	~GameScreen();
};

