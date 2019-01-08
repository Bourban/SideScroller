#pragma once
#include "Actor.h"
class Platform :
	public Actor
{
public:
	Platform(int height, int width, sf::Texture &texture);
	~Platform();
};

