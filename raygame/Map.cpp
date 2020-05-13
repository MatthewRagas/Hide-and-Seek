#include "Map.h"
#include <math.h>
Map::Map()
{
}

void Map::initializeGraph()
{
	//Remember the purpose of this function is to assign the location of each node on the grid, and set up each nodes neighboors.
	//Imagine this grid as creating nodes from left to right.
	//It will assign the x value of nodes until it gets to te maximum x value.
	//If it reaches the maximum x value it should increase on the y so it can set the x values for all nodes in the next row.
	//Its kinda like reading a book. Once you've read to the end of one line your eyes go down to the next.
	//In order to set this up we'll have to first set up some variables.
	//This first one sets the farthest posiible x value.
	int xMaximum = (int)sqrt(nodes.size()) - 1;

	//Now here create two variables of type integer; one called xPos and one called yPos.
	//Initialize them both to be 0.
	//This is how we'll keep track of the position the current node should be set to
	int xPos = 0;
	int yPos = 0;

	//Now we need two loops that can iterate through our list of nodes: one for setting the position of a node, and another for setting up the neighboors for that node
	//I'll leave the first one here for you
	for (std::vector<Node*>::iterator iterNode1 = nodes.begin(); iterNode1 != nodes.end(); ++iterNode1)
	{
		//set each nodes position to be the current x and the current y
		(*iterNode1)->position = { (float)xPos,(float)yPos };
		//This is probably the most confusing part
		//Create another for loop like the one before to set up the nieghboors.
		for (std::vector<Node*>::iterator iterNode2 = nodes.begin(); iterNode2 != nodes.end(); ++iterNode2)
		{
			//Inside it, you'll have to set up a list of conditions to check if a node is a neighboor of our current node
			//You can do this by checking the absolute value of the difference between the position of the node we check in the second loop and our current node.
			// For example a check to see if something is diagonal to us would look like this: 			

			if (abs((*iterNode2)->position.x - (*iterNode1)->position.x) == 1 && abs((*iterNode2)->position.y - (*iterNode1)->position.y) == 1)
			{
				(*iterNode2)->connections.push_back(new Connections(*iterNode1, 2));
				
			}
			else if (abs((*iterNode2)->position.x - (*iterNode1)->position.x) == 1 && abs((*iterNode2)->position.y == yPos))
			{
				(*iterNode2)->connections.push_back(new Connections(*iterNode1, 1));
			}
			else if (abs((*iterNode2)->position.x == xPos && abs((*iterNode2)->position.y - (*iterNode1)->position.y) == 1))
			{
				(*iterNode2)->connections.push_back(new Connections(*iterNode1, 1));
			}
			else if (abs((*iterNode2)->position.x == -2) && abs((*iterNode2)->position.y == -2))
			{
				continue;
			}
			//If we do this for all nodes, then anything within the distance of 1 will be considered as our neighboor.
			//For things that aren't diagonal, will simply just check to see if it shares the same column or row, and if it has a distance of 1
			//Checking if its on the same column or row is simply just checking to see if its x position or y position is the same as our current nodes
			//Lastly i chaeck to see if a node has not been given a location on the grid by seeing if its x and y are -2. If it is then i use the continue keyword
			//I ended up using 4 if statements for this but you could probably do it with less
			
		}
		//if x position variable is the same as the maximum x position, set x to be 0 and increase the y.
		if (xPos == xMaximum)
		{
			xPos = 0;
			yPos++;
			continue;
		}

		//otherwise increase x
		xPos++;

	}
}

void Map::draw(int scale)
{
	//loop through list of nodes and call draw for each node in list
	for (std::vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
	{
		(*iter)->Draw(scale);
	}
}

void Map::createGraph(int size)
{
	//create and add nodes to the list of nodes for the amount given in the argument list
	for (int i = 0; i <= size; i++)
	{
		nodes.push_back(new Node({ -2,-2 }));
	}
	//call initialize graph function to organize nodes
	initializeGraph();
}

Node* Map::findNode(Vector2 position)
{
	//Check the position of each node
	for (std::vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
	{
		//if the nodes position is the same as the one given in the argument list i return that node
		if ((*iter)->position == position)
		{
			return *iter;
		}
	}
	//otherwise return nullptr
	return nullptr;
}

int Map::findManhattan(Node * currentNode, Node * goal)
{
	//Calculate Manhattan Distance
	return abs(goal->position.x - currentNode->position.x) + abs(goal->position.y - currentNode->position.y);
}

void Map::reconstructPath(Node *startNode, Node * goalNode)
{
	//this function finds the right path by finding the parent of the goal node and repeating this 
	//process until it reaches the start node

	//First I create a node pointer to act as a iterator
	Node*iter = goalNode->parent;

	//loop through all nodes
	for (int i = 0; i < nodes.size(); i++)
	{
		//If the iterator is equal to the starting node return
		if (iter == startNode)
		{
			return;
		}

		//Set the node to a path node
		iter->isPathNode = true;
		//Set the node's parent to the iterator
		iter = iter->parent;

	}
}
bool Map::containsNode(std::vector<Node*>* list, Node * nodeToFind)
{
	std::vector<Node*>::iterator it = std::find(list->begin(), list->end(), nodeToFind);
	if (it != list->end())
	{
		return true;
	}
	return false;
}
void Map::removeNode(std::vector<Node*>* list, Node * unwantedNode)
{
	auto it = std::find(list->begin(), list->end(), unwantedNode);
	int index = std::distance(list->begin(), it);
	if (index == 0)
	{
		list->erase(list->begin());
		return;
	}
	list->erase(list->begin() + (index - 1));
}
void Map::sortNodeList(std::vector<Node*>* listPtr)
{
	Node* temp;

	//use bubble sort to sort the list and organize it by the f score
	for (std::vector<Node*>::iterator iterNode1 = nodes.begin(); iterNode1 != nodes.end(); iterNode1++)
	{
		for (std::vector<Node*>::iterator iterNode2 = nodes.begin(); iterNode2 != nodes.end(); iterNode2++)
		{
			if ((*iterNode1)->fScore > (*iterNode2)->fScore)
			{
				temp = (*iterNode2);
				(*iterNode2) = (*iterNode1);
				(*iterNode1) = temp;
			}
		}
	}

}
void Map::AStarSearch(Vector2 startPos, Vector2 endPos)
{
	//I'll leave everything that is exclusive to my implementation of A*
	Node* startNode = findNode(startPos);
	startNode->isStartNode = true;
	Node*goalNode = findNode(endPos);
	goalNode->isGoalNode = true;
	//intialize openlist
	std::vector<Node*> openList;

	//add the start node to the open list
	openList.push_back(startNode);

	std::vector<Node*>* openlistPtr = &openList;

	//create close list here
	std::vector<Node*> closedList;


	//Calculate the Manhattan distancefor the heuristic
	startNode->fScore = findManhattan(startNode, goalNode);

	//Create a while loop that loops while the size of the openlist is greater than 0
	//Loop while the openList's size is greater than 0
	while (!openList.empty())
	{
		//Use the sortNodeList function to sort the open list. You can pass in the opentlistPtr as the argument
		sortNodeList(&openList);
		//Create a Node* called currentNode. This will keep track of the node we are currently evaluating
		Node* currentNode = openList.front();

		//If current node is the same as the goal node call the reconstruct path function and return
		if (currentNode == goalNode)
		{
			reconstructPath(startNode, goalNode);
			return;
		}

		//Call the removeNodeFromList function and use openlistPtr and currentNode as the arguments
		removeNode(openlistPtr, currentNode);
		//Add current node to the closedlist
		closedList.push_back(currentNode);

		//Loop through all edges for the current node
		for (Connections* e : currentNode->connections)
		{
			//Check if the node at the end of the edge is in either the openlist or the closed list
			if (containsNode(&closedList, e->target) || containsNode(openlistPtr, e->target))
			{
				//If the statemnet is true continue
				continue;
			}

			else
			{
				//Set the neighbor's gScore to be the currentNode's gScore added to the edge's cost
				e->target->gScore = currentNode->gScore + e->cost;
				//Set the h score of the neighbor to be the hueristic
				e->target->hScore = findManhattan(e->target, goalNode);
				//Set the f score of the neighbor to be the g score of the neighbor added to the hueristic
				e->target->fScore = e->target->gScore + findManhattan(e->target, goalNode);
				//Set the parent of the neighbor to be the current node
				e->target->parent = currentNode;
				//Add neighbor to openlist
				openList.push_back(e->target);

			}
		}
	}
}