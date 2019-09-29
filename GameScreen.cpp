#include "GameScreen.h"


GameScreen::GameScreen() 
{
	currentBoi = 0;
}

void GameScreen::loadContent() 
{
	playerTexture.loadFromFile("Assets/Sprites/pls.png");
	playerIndicatorTexture.loadFromFile("Assets/Sprites/playerIndicator.png");
	barrelTexture.loadFromFile("Assets/Sprites/barrel.png");
	grassTexture.loadFromFile("Assets/Sprites/Grass.png");
	chestTexture.loadFromFile("Assets/Sprites/AwfulChest.png");

	font.loadFromFile("Assets/Fonts/Baldur.ttf");
	interactText.setFont(font);
}

int GameScreen::run(sf::RenderWindow & window)
{
	loadContent();
	inputHandler.bind();

	interactText.setPosition(400, 200);
	isPlayerOverlapWithInteractable = false;

#pragma region Populate Lists

	theBois.push_back(Character(elapsed, playerTexture));
	theBois.push_back(Character(elapsed, playerTexture));

	playerIndicator.setTexture(playerIndicatorTexture);

	for (int i = 0; i < theBois.size(); i++)
	{
		theBois[i].setPosition((i + 1) * 200, 400);
	}

	objects.push_back(StaticObject(barrelTexture, sf::Vector2f(140, 200), sf::Vector2f(500, 420)));

	for (int i = 0; i <= 3; i++) {
		objects.push_back(StaticObject(grassTexture, sf::Vector2f(300, 100), sf::Vector2f(i * 300, 620)));
	}

	objects.push_back(StaticObject(grassTexture, sf::Vector2f(300, 100), sf::Vector2f(900, 320)));
	
	interactables.push_back(InteractableObject(chestTexture, sf::Vector2f(100, 70), sf::Vector2f(1000, 250), "Press F to interact with this chest"));

#pragma endregion

	//main game loop

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
				if (event.key.code == sf::Keyboard::Q) {
					currentBoi--;
					if (currentBoi < 0) {
						currentBoi = theBois.size() - 1;
					}
				}
				break;

			}

		update(elapsed);

		render(window);
	}
	return 0;
}

void GameScreen::update(sf::Time delta)
{

#pragma region Collision Testing

	for (int i = 0; i < theBois.size(); i++) 
	{
		for (int j = 0; j < objects.size(); j++) 
		{
			if (theBois[i].platformCollisionCheck(objects[j].getRect())) {
				theBois[i].setIsJumping(false);
				break;
			}
			else {
				theBois[i].setIsJumping(true);
			}
		}
	}
	for (int i = 0; i < interactables.size(); i++)
	{
		if (theBois[currentBoi].platformCollisionCheck(interactables[i].getInteractionRect())) 
		{
				this->interactText.setString(interactables[i].getText());
				theBois[currentBoi].setOverlappingObject(interactables[i]);
				isPlayerOverlapWithInteractable = true;
				break;
			}
			else {
				isPlayerOverlapWithInteractable = false;
			
		}
			
	}

#pragma endregion

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

	for (auto sprite : objects) {
		window.draw(sprite);
	}

	for (auto sprite : interactables)
	{
		window.draw(sprite);
	}

	for (auto sprite : theBois)
	{
		window.draw(sprite);
	}

	if (isPlayerOverlapWithInteractable) 
	{
		window.draw(interactText);
	}

	window.draw(playerIndicator);

	window.display();
}


GameScreen::~GameScreen()
{
}
