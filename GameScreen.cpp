#include "GameScreen.h"


GameScreen::GameScreen() 
{
	
}

void GameScreen::loadContent() 
{
	grassTexture.loadFromFile("C:/Users/jorda/Downloads/PNG/Grass.png");
	playerTexture.loadFromFile("C:/Users/jorda/Downloads/Skeleton/Sprite_Sheets/Skeleton_Walk.png");
}

int GameScreen::run(sf::RenderWindow & window)
{
	loadContent();
	
	player = Player();
	player.setTexture(playerTexture);
	player.setTextureRect(sf::IntRect(264, 0, 22, 33));
	platforms.push_back(Platform(0, 520, 800, 200, grassTexture));
	player.setPosition(400, 0);

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
		player.update(elapsed);

		window.clear(sf::Color::Cyan);
		for (int i = 0; i < platforms.size(); i++)
		{
			window.draw(platforms[i]);
		}
		window.draw(player);
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

	
	for (int i = 0; i < platforms.size(); i++)
	{
		bool shouldBreak = player.platformCollisionCheck(platforms[i]);
		if (shouldBreak) {
			break;
		}
		
	}

	elapsed = clock.restart();
}


GameScreen::~GameScreen()
{
}
