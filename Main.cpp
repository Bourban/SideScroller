#include "Screens.h"
#include "Screen.h"
#include "SFML/Graphics/RenderWindow.hpp"

int main() {

	const int WINDOW_HEIGHT = 720;
	const int WINDOW_WIDTH = 1280;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SideScroller!");
	window.setFramerateLimit(60);

	//vector (list) of screen objects which contain each menu screen, level, etc.
	std::vector<Screen*> screens;

	//counter used to determine which screen is run next
	int currentScreen = 0;

	MenuScreen menu;
	screens.push_back(&menu);

	GameScreen game;
	screens.push_back(&game);

	//Loop contingent on each screen's run function returning a valid value
	while (currentScreen >= 0 && currentScreen <= screens.size())
	{
		currentScreen = screens[currentScreen]->run(window);

	}


	return 0;
}