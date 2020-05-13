#include "Node.h"

void Node::Draw(float scale)
{
	//Changes the color of the node based on the node's state
	if (isStartNode)
	{
		DrawRectangle(position.x * scale, position.y * scale, 10, 10, BLUE);
	}
	else if (isPathNode)
	{
		DrawRectangle(position.x * scale, position.y * scale, 10, 10, YELLOW);
	}
	else if (isGoalNode)
	{
		DrawRectangle(position.x * scale, position.y * scale, 10, 10, GREEN);
	}
	else
	{
		DrawRectangle(position.x * scale, position.y * scale, 10, 10, RED);
	}


	//Loop through the list of edges and draw them
	for (std::vector<Connections*>::iterator iterator = connections.begin(); iterator != connections.end(); iterator++)
	{
		//Draw edge
		(*iterator)->Draw(position, scale);
	}
}