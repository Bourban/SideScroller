#include "InputHandler.h"

Command* InputHandler::handleInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		return keyboardW;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		return keyboardA;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		return keyboardS;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		return keyboardD;
	}
	return NULL;
}

void InputHandler::bind()
{
	keyboardW = new MoveCommand();

}
