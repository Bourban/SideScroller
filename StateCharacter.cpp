#include "StateCharacter.h"
#include <iostream>


StateCharacter::StateCharacter()
{
}

StateCharacter::StateCharacter(sf::Texture &texture, int rows, int cols, int x, int y)
{
	//this->m_pTexture = &texture;
	this->setTexture(texture);

	//get the size of each frame from the size of the texure and the amount of frames,
	//if there's only one then it should equal the total size of the texture.
	if (cols == 0 || rows == 0) {
		std::cout << "You idiot";	
	}
	else {
		m_frameHeight = texture.getSize().y / cols;
		m_frameWidth = texture.getSize().x / rows;
	}

	//Placeholder line until animation system is in
	this->setTextureRect(sf::IntRect(264, 0, 22, 33));


	this->setOrigin(sf::Vector2f(m_frameWidth * 0.5f, m_frameHeight * 0.5f));

	m_bottom.width = m_frameWidth;
	m_bottom.height = 10;

	this->setPosition(x, y);

	m_state = idle;
}


void StateCharacter::handleSpriteFacing()
{
	//as long as origin is at center this will turn the charater on the spot
	if (m_isFacingLeft) {
		this->setScale(sf::Vector2f(-1, 1));
	}
	else {
		this->setScale(sf::Vector2f(1, 1));
	}
}

void StateCharacter::handleFallingSpeed()
{
	if (m_state == jumping){
		if (this->m_deltaY > -400)
		{
			//exactly 1 second before we start falling
			m_deltaY -= 450 * m_pElapsed->asSeconds();
		}
		else {
			m_deltaY = -400;
		}
	}
	else {
		this->m_deltaY = 0;
	}
}

bool StateCharacter::platformCollisionCheck(Platform & platform)
{
	if (m_bottom.intersects(platform.getRect()) && m_deltaY <= 0)
	{
		m_state = idle;
		return true;
	}
	else {
		return false;
	}
}

void StateCharacter::update(sf::Time & time)
{
	//this doesn't need to happen every frame, move to a constructor or make the timer accessible from here
	this->m_pElapsed = &time;

	this->move(0, -(m_deltaY * m_pElapsed->asSeconds()));

	//replace with window height -20 for scalability
	if (this->getPosition().y > 600)
	{
		this->setPosition(this->getPosition().x, 600);
		m_state = idle;
	}

	m_bottom.left = this->getPosition().x;
	m_bottom.top = this->getPosition().y + m_spriteHeight - 10;

	this->handleFallingSpeed();
	this->handleSpriteFacing();

	switch (m_state) {
	case idle:
		std::cout << "idle";
	case crouching:
		std::cout << "crouching";
	case jumping:
		std::cout << "jumping";
	}
}

void StateCharacter::moveLeft()
{
	if (m_state == crouching) {
		this->move(-150 * m_pElapsed->asSeconds(), 0);
		m_isFacingLeft = true;
	}
	else {
		this->move(-300 * m_pElapsed->asSeconds(), 0);
		m_isFacingLeft = true;
	}
}

void StateCharacter::moveRight()
{
	if (m_state == crouching) {
		this->move(150 * m_pElapsed->asSeconds(), 0);
		m_isFacingLeft = false;
	}
	else {
		this->move(300 * m_pElapsed->asSeconds(), 0);
		m_isFacingLeft = false;
	}
}

void StateCharacter::jump()
{
	switch (m_state) {
	case idle:
		m_deltaY = 450;
		m_state = jumping;
		break;

	case crouching:
		//change animations
		m_state = idle;
		break;

	default:
		break;
	}
}



StateCharacter::~StateCharacter()
{
}

