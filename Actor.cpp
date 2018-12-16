#include "Actor.h"



Actor::Actor()
{
}


Actor::~Actor()
{
}

sf::RectangleShape Actor::getRect()
{
	return this->box;
}
