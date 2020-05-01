#include "BehaviorDecision.h"
#include "Behavior.h"

void BehaviorDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (m_behavior == nullptr)
		return;

	m_behavior->update(agent, deltaTime);
}