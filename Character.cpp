#include "Character.h"
#include <iostream>


Character::Character()
{
}


Character::~Character()
{
}


void Character::update(sf::Time &time)
{
	this->m_elapsed = &time;

	this->move(0, -(m_deltaY * m_elapsed->asSeconds()));

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
		if (this->m_deltaY > -500)
		{
			m_deltaY -= 1000 * m_elapsed->asSeconds();
		};
	}
	else {
		this->m_elapsed = 0;
	}
}

void Character::platformCollisionCheck(Platform & platform)
{
	if (m_bottom.intersects(platform.getRect()) && m_deltaY <=0) 
	{
		m_isOnGroud = true;
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
		m_deltaY = 550;
		m_isOnGroud = false;
	}
}

void Character::attack()
{
	std::cout << "Attacking" << "\n";
}