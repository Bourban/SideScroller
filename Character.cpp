#include "Character.h"
#include <iostream>

Character::Character()
{
}

Character::Character(sf::Time & time, sf::Texture & texture) : Sprite(texture)
{
	pElapsedTime = &time;

	currentState = idle;

	this->spriteSize = sf::Vector2f(512, 512);

	this->setOrigin(this->spriteSize / 2.0f);
}

Character::~Character()
{
}

void Character::jump()
{
	if (currentState != jumping) {
		
		//at the end of this block
		//currentState = jumping;
	}
	std::cout << "jump";
}

void Character::moveLeft()
{
	if (currentState == idle || currentState == moving) {
		this->move(-300 * pElapsedTime->asSeconds(), 0);
		bIsFacingLeft = true;
		currentState = moving;

	}
}

void Character::moveRight()
{
	if (currentState == idle || currentState == moving) {
		this->move(300 * pElapsedTime->asSeconds(), 0);
		bIsFacingLeft = false;
		currentState = moving;
	}
}

void Character::attack()
{
}

void Character::update()
{
	this->handleSpriteFacing();

}

void Character::handleSpriteFacing()
{

	if (bIsFacingLeft) {
		this->setScale(sf::Vector2f(-1, 1));
	}
	else {
		this->setScale(sf::Vector2f(1, 1));
	}

}
