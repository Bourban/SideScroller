#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"
#include "InteractableObject.h"


class GameScreen :
	public Screen
{
public:

	virtual int run(sf::RenderWindow &window);

	void update(sf::Time delta);
	void render(sf::RenderWindow & window);
	void loadContent();


	GameScreen();
	~GameScreen();

private:

	sf::Texture playerTexture;
	sf::Texture playerIndicatorTexture;
	sf::Texture barrelTexture;
	sf::Texture grassTexture;
	sf::Texture chestTexture;

	sf::Sprite playerIndicator;

	sf::Font font;
	sf::Text interactText;

	int currentBoi;
	std::vector<Character> theBois;

	std::vector<StaticObject> objects;
	std::vector<InteractableObject> interactables;

	const float TIME_PER_UPDATE = 0.016f;

	bool isGameOver;
	bool isPlayerOverlapWithInteractable;

	sf::Clock clock;
	sf::Time elapsed;

	InputHandler inputHandler;
};

