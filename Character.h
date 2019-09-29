#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include "StaticObject.h"
#include "InteractableObject.h"

//Player Character class -- The player controls several of these and can switch between them easily with the Q and E keys

class Character : public sf::Sprite {

public:
	Character();

	Character(sf::Time &time, sf::Texture &texture);

	~Character();

	void jump();
	void moveLeft();
	void moveRight();
	void attack();
	void interact();

	void update();

	bool platformCollisionCheck(sf::IntRect &other);

	void setOverlappingObject(InteractableObject & other);
	void setIsJumping(bool value);

	sf::Vector2f getSpriteSize();

	sf::RectangleShape pls;

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

	InteractableObject* overlappingObject;
};
