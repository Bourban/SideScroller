#pragma once
#include "StaticObject.h"

class InteractableObject :
	public StaticObject
{
public:
	InteractableObject();
	InteractableObject(sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos);
	~InteractableObject();

	sf::IntRect getInteractionRect();

private:
	sf::IntRect interactionRect;
};

