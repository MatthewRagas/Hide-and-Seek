#include "Connections.h"
#include "Node.h"

Connections::Connections()
{
}
Connections::Connections(Node * newTarget, float newCost = 0)
{
	target = newTarget;
	cost = newCost;
	drawColor = BLACK;
}
void Connections::Draw(Vector2 startPos, float scale)
{
	DrawLine(startPos.x * scale, startPos.y * scale, target->position.x * scale, target->position.y * scale, drawColor);
}