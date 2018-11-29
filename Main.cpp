#include "Screens.h"
#include "Screen.h"
#include "SFML\Graphics\RenderWindow.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SideScroller!");

	std::vector<Screen*> screens;
	int currentScreen = 0;

	MenuScreen menu;
	screens.push_back(&menu);

	GameScreen game;
	screens.push_back(&game);

	//Loop contingent on each screen's run function returning a valid value
	while (currentScreen >= 0 || currentScreen > screens.size)
	{
		currentScreen = screens[currentScreen]->run(window);

	}


	return 0;
}