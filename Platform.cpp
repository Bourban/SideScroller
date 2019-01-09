#include "Platform.h"


Platform::Platform(int x, int y,int width, int height, sf::Texture &texture)
{
	m_box.height = height;
	m_box.width = width;

	this->setPosition(x, y);

	m_box.top = y;
	m_box.left = x;

	this->setTexture(texture);

}

Platform::Platform()
{
}

Platform::~Platform()
{
}
