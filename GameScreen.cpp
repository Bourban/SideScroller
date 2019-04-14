#include "GameScreen.h"


GameScreen::GameScreen() 
{
	currentBoi = 0;
}

void GameScreen::loadContent() 
{
	playerTexture.loadFromFile("Assets/Sprites/pls.png");
	playerIndicatorTexture.loadFromFile("Assets/Sprites/playerIndicator.png");
}

int GameScreen::run(sf::RenderWindow & window)
{
	loadContent();
	inputHandler.bind();

	theBois.push_back(Character(elapsed, playerTexture));
	theBois.push_back(Character(elapsed, playerTexture));

	playerIndicator.setTexture(playerIndicatorTexture);

	for (int i = 0; i < theBois.size(); i++)
	{
		theBois[i].setPosition((i + 1) * 200, 400);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					return 0;
				}
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::E) {
					currentBoi++;
					currentBoi = currentBoi % theBois.size();
				}
			}

		update(elapsed);

		render(window);
	}
	return 0;
}

void GameScreen::update(sf::Time delta)
{

	for (int i = 0; i < theBois.size(); i++)
	{
		theBois[i].update();
	}

	playerIndicator.setPosition(theBois[currentBoi].getPosition().x, theBois[currentBoi].getPosition().y  - (theBois[currentBoi].getSpriteSize().y / 2));

	Command* command = inputHandler.handleInput();
	if (command)
	{
		command->execute(theBois[currentBoi]);
	}

	elapsed = clock.restart();
}

void GameScreen::render(sf::RenderWindow & window)
{
	window.clear(sf::Color::Cyan);
	for (int i = 0; i < theBois.size(); i++)
	{
		window.draw(theBois[i]);
	}

	window.draw(playerIndicator);

	window.display();
}


GameScreen::~GameScreen()
{
}
