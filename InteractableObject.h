#pragma once
#include "StaticObject.h"

class InteractableObject :
	public StaticObject
{
public:
	InteractableObject();
	InteractableObject(sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos);
	InteractableObject(sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos, std::string text);
	~InteractableObject();

	void interact();

	sf::IntRect getInteractionRect();
	std::string getText();

private:
	std::string text;
	sf::IntRect interactionRect;
};

