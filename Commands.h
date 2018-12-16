#pragma once

#include "SFML\Graphics\CircleShape.hpp"
#include "SFML\System\Vector2.hpp"

class Command 
{
public:
	virtual ~Command(){}
	virtual void execute(sf::CircleShape &shape) = 0;
};


class MoveCommand : public Command
{
public:
	virtual void execute(sf::CircleShape &shape) 
	{
		//this should be a method in actor class 
		shape.move(0,0);
	};
};