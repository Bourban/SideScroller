#pragma once

#include "Commands.h"
#include "SFML\Window\Keyboard.hpp"

class InputHandler
{
public: 
	Command* handleInput();

	void bind();

private:
	Command* keyboardW;
	Command* keyboardA;
	Command* keyboardS;
	Command* keyboardD;
	Command* keyboardSpace;
};

