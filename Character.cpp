#include "Character.h"
#include <iostream>


Character::Character()
{
	m_spriteHeight = 33;
	m_spriteWidth = 22;

	m_bottom.width = m_spriteWidth;
	m_bottom.height = 10;
}


Character::~Character()
{
}


void Character::update(sf::Time &time)
{
	this->m_elapsed = &time;

	this->move(0, -(m_deltaY * m_elapsed->asSeconds()));

	m_bottom.left = this->getPosition().x;
	m_bottom.top = this->getPosition().y + m_spriteHeight;

	this->handleFallingSpeed();
	this->handleSpriteFacing();
}

void Character::handleSpriteFacing()
{
	if (m_isFacingLeft) {
		this->setScale(sf::Vector2f(-1, 1));
	}
	else {
		this->setScale(sf::Vector2f(1, 1));
	}

}

void Character::handleFallingSpeed()
{
	if (!m_isOnGroud) {
		if (this->m_deltaY > -200)
		{
			m_deltaY -= 400 * m_elapsed->asSeconds();
		}
		else {
			m_deltaY = -200;
		}
	}
	else {
		this->m_deltaY = 0;
	}
}

bool Character::platformCollisionCheck(Platform & platform)
{
	//Needs to be updated - this will only work for checking one platform.
	//Maybe change to a bool and return true or false to break the for loop as required
	if (m_bottom.intersects(platform.getRect()) && m_deltaY <=0) 
	{
		m_isOnGroud = true;
		return true;
	}
	else {
		m_isOnGroud = false;
		return false;
	}
}

void Character::moveLeft()
{
	this->move(-220 * m_elapsed->asSeconds(), 0);
	m_isFacingLeft = true;
}

void Character::moveRight()
{
	this->move(220 * m_elapsed->asSeconds(), 0);
	m_isFacingLeft = false;
}

void Character::jump()
{
	if (m_isOnGroud) {
		m_deltaY = 450;
		m_isOnGroud = false;
	}
}

void Character::attack()
{
	std::cout << "Attacking" << "\n";
}
