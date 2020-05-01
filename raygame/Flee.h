#pragma once
#include "Behavior.h"

class Flee : public Behavior
{
public:
	Flee() {}
	virtual ~Flee() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }


protected:
	Agent* m_target = nullptr;
};

