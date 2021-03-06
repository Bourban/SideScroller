#include "Character.h"
#include <SFML\Graphics\Texture.hpp>
#include <iostream>

Character::Character()
{
}

Character::Character(sf::Time & time, sf::Texture & texture) : Sprite(texture)
{
	pElapsedTime = &time;

	currentState = idle;

	this->spriteSize = (sf::Vector2f) texture.getSize();

	this->setOrigin(this->spriteSize / 2.0f);

	this->bottomRect.height = 20;
	this->bottomRect.width = 100;

	this->bIsJumping = false;
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

void Character::interact()
{
	overlappingObject->interact();
}

void Character::update()
{
	this->handleSpriteFacing();

	this->bottomRect.left = this->getPosition().x - 30;
	this->bottomRect.top = this->getPosition().y + 140;

	pls.setPosition(bottomRect.left, bottomRect.top);
	pls.setSize(sf::Vector2f(bottomRect.width, bottomRect.height));

	if (bIsJumping) {
		this->move(0, -(deltaY * pElapsedTime->asSeconds()));
		if (deltaY > -450) {
			deltaY -= 600 * pElapsedTime->asSeconds();
		}
	}

	if (this->getPosition().y > 550) {
		bIsJumping = false;
		this->setPosition(this->getPosition().x, 0);
	}
}

bool Character::platformCollisionCheck(sf::IntRect & other)
{
	if (this->bottomRect.intersects(other) && this->deltaY <= 0)
		return true;
	else
		return false;
}

void Character::setOverlappingObject(InteractableObject & other)
{
	overlappingObject = &other;
}

void Character::setIsJumping(bool value)
{
	this->bIsJumping = value;
}



sf::Vector2f Character::getSpriteSize()
{
	return this->spriteSize;
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

