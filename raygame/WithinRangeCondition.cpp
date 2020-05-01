#include "WithinRangeCondition.h"


bool WithinRangeCondition::test(Agent* agent) const
{
	//Get targets position
	Vector2 targetPos = m_target->getPosition();

	//Get agent's position
	Vector2 position = agent->getPosition();

	//Find the distance
	float distance = (targetPos - position).magnitude();

	//Return result
	return distance <= m_range;
}