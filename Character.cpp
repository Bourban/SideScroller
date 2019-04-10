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
	if (!bIsJumping) {
		deltaY = 500;
		bIsJumping = true;
	}
}

void Character::moveLeft()
{
	if (currentState != attacking) {
		this->move(-300 * pElapsedTime->asSeconds(), 0);
		bIsFacingLeft = true;
		currentState = moving;

	}
}

void Character::moveRight()
{
	if (currentState != attacking) {
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


	if (bIsJumping) {
		this->move(0, -(deltaY * pElapsedTime->asSeconds()));
		if (deltaY > -450) {
			deltaY -= 600 * pElapsedTime->asSeconds();
		}
	}

	if (this->getPosition().y > 550)
		bIsJumping = false;
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
