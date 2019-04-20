#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"


class MenuScreen :
	public Screen
{
public:

	virtual int run(sf::RenderWindow &window);

	void update();
	void render(sf::RenderWindow &window);

	MenuScreen();
	~MenuScreen();

private:

	sf::Font font;
	sf::Text test;

};

