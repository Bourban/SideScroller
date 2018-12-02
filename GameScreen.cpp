#include "GameScreen.h"



int GameScreen::run(sf::RenderWindow & window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}

GameScreen::GameScreen()
{
}


GameScreen::~GameScreen()
{
}
