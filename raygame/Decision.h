#pragma once
#include "Agent.h"

/*	Decision
A Decision is one node on a decision tree. Decision is pure
virtual, and inherited classes need to be created. Those
inherited classes will implement makeDecision, which can
lead to another Decision, perform a Behavior, or take some
other action.
*/

class Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};

