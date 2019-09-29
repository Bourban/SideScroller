#include "InputHandler.h"

Command* InputHandler::handleInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		return keyboardSpace;
	}
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		return keyboardF;
	}
	return NULL;
}

void InputHandler::bind()
{
	//movement
	keyboardW = new JumpCommand();
	keyboardA = new MoveLeftCommand();
	keyboardD = new MoveRightCommand();

	//actions
	keyboardF = new InteractCommand();
	keyboardSpace = new JumpCommand();
}
