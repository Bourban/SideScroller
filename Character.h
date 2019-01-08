#pragma once
#include "Actor.h"
#include "SFML\System\Clock.hpp"
#include "Platform.h"

//Base class of Player and Enemy for use with command method calls

class Character :
	public Actor
{
public:
	Character();
	~Character();

	void update(sf::Time &time);
	void handleSpriteFacing();
	void handleFallingSpeed();

	void platformCollisionCheck(Platform &platform);

	void moveLeft();
	void moveRight();
	void jump();

	void attack();

protected:

	sf::Time* m_elapsed;
	sf::FloatRect m_bottom;

	float m_deltaY;
	bool m_isOnGroud;
	bool m_isFacingLeft;
};

