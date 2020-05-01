#include "Flee.h"

Vector2 Flee::update(Agent * agent, float deltaTime)
{
	//If target is null
	if (agent == nullptr || m_target == nullptr)
	{
		//Return a 0 vector
		return Vector2();
	}

	

	//Get this agent's position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	Vector2 target_Pos = m_target->getPosition();

	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = pos - target_Pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	Vector2 force = direction * agent->getSpeed();
	//Subtract the agent's current velocity from the result to get the force we need to apply
	force = force - agent->getVelocity();

	//Return the force
	agent->addForce(force * deltaTime);

	//Change color
	agent->setColor(MAROON);

	return Vector2();
}
