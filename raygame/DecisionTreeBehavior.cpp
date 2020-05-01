#include "DecisionTreeBehavior.h"

Vector2 DecisionTreeBehavior::update(Agent * agent, float deltaTime)
{
	m_rootDecision->makeDecision(agent, deltaTime);
	
	return Vector2();
}
