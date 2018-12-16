#pragma once
#include "Actor.h"

//Base class of Player and Enemy for use with command method calls

class Character :
	public Actor
{
public:
	Character();
	~Character();
};

