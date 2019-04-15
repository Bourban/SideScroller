#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"


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

	sf::Sprite playerIndicator;

	int currentBoi;
	std::vector<Character> theBois;

	std::vector<StaticObject> objects;

	const float TIME_PER_UPDATE = 0.016f;

	bool isGameOver;

	sf::Clock clock;
	sf::Time elapsed;

	InputHandler inputHandler;
};

