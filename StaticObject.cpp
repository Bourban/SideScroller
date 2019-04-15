#include "StaticObject.h"



StaticObject::StaticObject()
{
}

StaticObject::StaticObject(sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos) : Sprite(texture)
{
	this->setPosition(pos);

	this->rect.height = size.y;
	this->rect.width = size.x;
	this->rect.left = pos.x;
	this->rect.top = pos.y;

	pls.setOutlineColor(sf::Color::Black);
	pls.setFillColor(sf::Color::Blue);
	pls.setPosition(rect.left, rect.top);
	pls.setSize(size);
}


StaticObject::~StaticObject()
{
}

sf::IntRect StaticObject::getRect()
{
	return this->rect;
}
