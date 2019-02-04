#include "Character.h"
#include <iostream>


Character::Character(sf::Texture &texture, int x, int y)
{
	this->m_texture = &texture;
	this->setTexture(*(m_texture));

	this->setTextureRect(sf::IntRect(264, 0, 22, 33));

	//m_spriteHeight = m_texture->getSize().y;
	//m_spriteWidth = m_texture->getSize().x;

	m_spriteHeight = 33;
	m_spriteWidth = 22;

	this->setOrigin(sf::Vector2f(m_spriteWidth / 2, m_spriteHeight / 2));

	m_bottom.width = m_spriteWidth;
	m_bottom.height = 10;

	this->setPosition(x, y);
}


Character::Character()
{
	m_spriteHeight = 33;
	m_spriteWidth = 22;

	this->setOrigin(sf::Vector2f(m_spriteWidth / 2, m_spriteHeight / 2));

	m_bottom.width = m_spriteWidth;
	m_bottom.height = 10;
}


Character::~Character()
{
}


void Character::update(sf::Time &time)
{
	//this doesn't need to happen every frame, move to a constructor or make the timer accessible from here
	this->m_elapsed = &time;

	this->move(0, -(m_deltaY * m_elapsed->asSeconds()));

	//replace with window height -20 for scalability
	if(this->getPosition().y > 600)
	{
		this->setPosition(this->getPosition().x, 600);
		m_isOnGroud = true;
	}

	m_bottom.left = this->getPosition().x;
	m_bottom.top = this->getPosition().y + m_spriteHeight - 10;

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
		if (this->m_deltaY > -400)
		{
			//exactly 1 second before we start falling
			m_deltaY -= 450 * m_elapsed->asSeconds();
		}
		else {
			m_deltaY = -400;
		}
	}
	else {
		this->m_deltaY = 0;
	}
}

bool Character::platformCollisionCheck(Platform & platform)
{
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
	this->move(-300 * m_elapsed->asSeconds(), 0);
	m_isFacingLeft = true;
}

void Character::moveRight()
{
	this->move(300 * m_elapsed->asSeconds(), 0);
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
