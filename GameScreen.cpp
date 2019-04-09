#include "GameScreen.h"


GameScreen::GameScreen() 
{
	
}

void GameScreen::loadContent() 
{
	playerTexture.loadFromFile("Assets/Sprites/pls.png");
}

int GameScreen::run(sf::RenderWindow & window)
{
	loadContent();
	inputHandler.bind();

	player = Character(elapsed, playerTexture);
	player.setPosition(400, 400);


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

		render(window);
	}
	return 0;
}

void GameScreen::update(sf::Time delta)
{
	player.update();

	Command* command = inputHandler.handleInput();
	if (command)
	{
		command->execute(player);
	}

	elapsed = clock.restart();
}

void GameScreen::render(sf::RenderWindow & window)
{
	window.clear(sf::Color::Cyan);
	window.draw(player);
	window.display();
}


GameScreen::~GameScreen()
{
}
