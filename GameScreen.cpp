#include "GameScreen.h"


GameScreen::GameScreen() 
{
	player = Player();
}


int GameScreen::run(sf::RenderWindow & window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	inputHandler.bind();

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

		update(elapsed);

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}

void GameScreen::update(sf::Time delta)
{
	player.update(delta);

	Command* command = inputHandler.handleInput();
	if (command)
	{
		command->execute(player);
	}

	elapsed = clock.restart();
}


GameScreen::~GameScreen()
{
}
