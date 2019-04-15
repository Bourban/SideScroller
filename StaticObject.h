#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
class StaticObject :
	public sf::Sprite
{
public:
	StaticObject();
	StaticObject(sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos);

	~StaticObject();

	sf::IntRect getRect();

	sf::RectangleShape pls;

private:
	
	sf::IntRect rect;

};

