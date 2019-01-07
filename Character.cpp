#include "Character.h"
#include <iostream>


Character::Character()
{
}


Character::~Character()
{
}

void Character::updateTime(sf::Time &time)
{
	this->m_elapsed = &time;
}

void Character::moveLeft()
{
	this->move(-5 * m_elapsed->asSeconds(), 0);
	std::cout << "Left" << "\n";
}

void Character::moveRight()
{
	this->move(5 * m_elapsed->asSeconds(), 0);
	std::cout << "Right" << "\n";
}

void Character::attack()
{
	std::cout << "Attacking" << "\n";
}
