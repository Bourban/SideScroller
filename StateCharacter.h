#pragma once

#include "SFML\System\Time.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "Actor.h"
#include "Platform.h"

class StateCharacter :
	public Actor
{
public:
	StateCharacter();
	StateCharacter(sf::Texture &texture, int rows, int cols, int x, int y);
	~StateCharacter();

	bool platformCollisionCheck(Platform &platform);

	void update(sf::Time &time);

	void moveLeft();
	void moveRight();
	void jump();
	void attack();

protected:
	void handleSpriteFacing();
	void handleFallingSpeed();

	enum state { idle, jumping, crouching, attacking };
	state m_state;

	sf::Time* m_pElapsed;
	//sf::Texture* m_pTexture;
	sf::FloatRect m_bottom;

	float m_deltaY;
	bool m_isFacingLeft;
};

