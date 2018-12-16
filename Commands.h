#pragma once

#include "Character.h"

class Command 
{
public:
	virtual ~Command(){}
	virtual void execute(Character &target) = 0;
};


class MoveLeftCommand : public Command
{
public:
	virtual void execute(Character &target)
	{
		//this should be a method in actor class 
		target.moveLeft();
	};
};

class MoveRightCommand : public Command
{
public:
	virtual void execute(Character &target)
	{
		//this should be a method in actor class 
		target.moveRight();
	};
};

class AttackCommand : public Command
{
public:
	virtual void execute(Character &target)
	{
		//this should be a method in actor class 
		target.attack();
	};
};