#pragma once
#include "Decision.h"

/*	BehaviorDecision
A BehaviorDecision is a Decision that stores a Behavior.
When makeDecision is called, the stored Behavior's
update() function is called.
*/

class BehaviorDecision : public Decision
{
public:
	BehaviorDecision(Behavior* behavior) : m_behavior(behavior) {}
	~BehaviorDecision() {}

	virtual void makeDecision(Agent* agent, float deltaTime);

private:
	Behavior* m_behavior = nullptr;
};
