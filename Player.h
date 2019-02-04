#pragma once
#include "Character.h"
#include <SFML/Graphics/Texture.hpp>

class Player :
	public Character
{
public:
	Player();
	Player(sf::Texture &texture, int x, int y) : Character(texture, x, y) {};
	~Player();

private:
	sf::Time* elapsed;
};

