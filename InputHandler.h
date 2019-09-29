#pragma once

#include "Commands.h"
#include "SFML\Window\Keyboard.hpp"

//Class which handles player input -- binds keys to specific commands and checks for key presses

class InputHandler
{
public: 
	Command* handleInput();

	void bind();

private:
	Command* keyboardF;
	Command* keyboardW;
	Command* keyboardA;
	Command* keyboardS;
	Command* keyboardD;
	Command* keyboardSpace;
};

