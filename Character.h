#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Rect.hpp>
#include "StaticObject.h"

class Character : public sf::Sprite {

public:
	Character();

	Character(sf::Time &time, sf::Texture &texture);

	~Character();

	void jump();
	void moveLeft();
	void moveRight();
	void attack();

	void update();

	bool platformCollisionCheck(sf::IntRect &other);
	void setIsJumping(bool &value);

	sf::Vector2f getSpriteSize();

private:

	enum State
	{
		idle,
		moving,
		attacking,
		jumping
	};

	sf::IntRect bottomRect;

	State currentState;

	sf::Time* pElapsedTime;
	sf::Vector2f spriteSize;

	bool bIsFacingLeft;
	bool bIsJumping;

	float deltaY;

	void handleSpriteFacing();

};
