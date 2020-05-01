#pragma once
#include "Agent.h"

class Behavior
{
public:
	Behavior() {}
	virtual ~Behavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime) = 0;

};

