#pragma once
#include "Behavior.h"

class WanderBehavior : public Behavior
{
public:
	WanderBehavior() {}
	virtual ~WanderBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);	

private:
	float m_radius = 50.0f;
	float m_offset = 0.0f;
	float m_jitter = 10.0f;

	Vector2 m_prevTarget = { 0.0f, 0.0f };
};

