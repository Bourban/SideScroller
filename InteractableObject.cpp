#include "InteractableObject.h"



InteractableObject::InteractableObject()
{
}

InteractableObject::InteractableObject(sf::Texture & texture, sf::Vector2f size, sf::Vector2f pos) : StaticObject(texture, size, pos)
{
	this->interactionRect.height = size.y * 3;
	this->interactionRect.width = size.x * 3;
	this->interactionRect.left = pos.x - size.x;
	this->interactionRect.top = pos.y - size.y;

}


InteractableObject::~InteractableObject()
{
}

sf::IntRect InteractableObject::getInteractionRect()
{
	return this->interactionRect;
}
