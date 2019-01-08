#include "Platform.h"


Platform::Platform(int height, int width, sf::Texture &texture)
{
	m_box.height = height;
	m_box.width = width;

	m_box.top = this->getPosition().y;
	m_box.left = this->getPosition().x;

	this->setTexture(texture);

}


Platform::~Platform()
{
}
