#pragma once
#include "StateCharacter.h"
#include <SFML/Graphics/Texture.hpp>

class Player :
	public StateCharacter
{
public:
	Player();
	Player(sf::Texture &texture, int rows, int cols, int x, int y) : StateCharacter(texture, rows, cols, x , y) {};
	~Player();

};

