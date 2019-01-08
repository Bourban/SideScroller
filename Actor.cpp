#include "Actor.h"



Actor::Actor()
{
}


Actor::~Actor()
{
}

sf::FloatRect Actor::getRect() const
{
	return m_box;
}
