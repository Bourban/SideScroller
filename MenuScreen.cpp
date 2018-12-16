#include "MenuScreen.h"



int MenuScreen::run(sf::RenderWindow & window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.setFramerateLimit(60.0f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			return 1;
		
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return -1;
}

MenuScreen::MenuScreen()
{
}


MenuScreen::~MenuScreen()
{
}
