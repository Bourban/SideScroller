#pragma once
#include "Actor.h"
class Platform :
	public Actor
{
public:
	Platform(int x, int y, int width, int height, sf::Texture &texture);
	Platform();
	~Platform();
};

