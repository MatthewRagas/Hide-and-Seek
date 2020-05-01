#pragma once
#include "Behavior.h"

class seekBehavior : public Behavior
{
public:
	seekBehavior() {}
	virtual ~seekBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;

};