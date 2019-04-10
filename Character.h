#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>

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

private:

	enum State
	{
		idle,
		moving,
		attacking,
		jumping
	};

	State currentState;

	sf::Time* pElapsedTime;
	sf::Vector2f spriteSize;

	bool bIsFacingLeft;
	bool bIsJumping;

	float deltaY;

	void handleSpriteFacing();

};
