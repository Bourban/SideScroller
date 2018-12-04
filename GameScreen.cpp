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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			return 0;

		}


		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}

void GameScreen::update(sf::Time delta)
{


}

GameScreen::GameScreen()
{
}


GameScreen::~GameScreen()
{
}
