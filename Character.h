#pragma once
#include "Actor.h"
#include "SFML\System\Clock.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "Platform.h"

//Base class of Player and Enemy for use with command method calls

class Character :
	public Actor
{
public:
	Character(sf::Texture &texture, int x, int y);
	Character();
	~Character();

	void update(sf::Time &time);

	bool platformCollisionCheck(Platform &platform);

	void moveLeft();
	void moveRight();
	void jump();

	void attack();

protected:

	sf::Time* m_pElapsed;
	sf::Texture* m_pTexture;
	sf::FloatRect m_bottom;

	void handleSpriteFacing();
	void handleFallingSpeed();

	float m_deltaY;
	bool m_isOnGroud;
	bool m_isFacingLeft;
};

