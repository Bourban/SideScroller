#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"
#include "Player.h"

class GameScreen :
	public Screen
{
public:

	virtual int run(sf::RenderWindow &window);

	void update(sf::Time delta);

	GameScreen();
	~GameScreen();

private:

	const float TIME_PER_UPDATE = 0.016f;

	bool isGameOver;

	sf::Clock clock;
	sf::Time elapsed;

	InputHandler inputHandler;

	Player player;

};

