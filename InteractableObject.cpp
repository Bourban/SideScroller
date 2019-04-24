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
	this->text = "Press F to pay respects";

}

InteractableObject::InteractableObject(sf::Texture & texture, sf::Vector2f size, sf::Vector2f pos, std::string text) : StaticObject(texture, size, pos)
{
	this->interactionRect.height = size.y * 3;
	this->interactionRect.width = size.x * 3;
	this->interactionRect.left = pos.x - size.x;
	this->interactionRect.top = pos.y - size.y;
	this->text = text;
}


InteractableObject::~InteractableObject()
{
}

void InteractableObject::interact()
{
	this->~InteractableObject();
}

sf::IntRect InteractableObject::getInteractionRect()
{
	return this->interactionRect;
}

std::string InteractableObject::getText()
{
	return this->text;
}
