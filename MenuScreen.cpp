#include "MenuScreen.h"



int MenuScreen::run(sf::RenderWindow & window)
{
	font.loadFromFile("Assets/Fonts/Baldur.ttf");
	test.setFont(font);

	test.setString("Press Enter to Proceed to the game");
	test.setPosition(200, 200);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			return 1;
		}

		update();
		render(window);

	}
	 
	return -1;
}

void MenuScreen::update()
{
}

void MenuScreen::render(sf::RenderWindow &window) {

	window.clear(sf::Color::Blue);
	window.draw(test);
	window.display();

}


MenuScreen::MenuScreen()
{
}


MenuScreen::~MenuScreen()
{
}
