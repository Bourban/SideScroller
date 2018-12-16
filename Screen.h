#pragma once
#include "SFML\Graphics\RenderWindow.hpp"
#include "InputHandler.h"

class Screen
{
public:
	virtual int run(sf::RenderWindow &window) = 0;

};

