#pragma once
#include "raylib.h"
#include "Node.h"
class Map
{
public:
	Map();
	//List of all nodes
	std::vector<Node*> nodes;
	//To sets up nodes position on grid with proper connections
	void initializeGraph();
	//draws grid. Scale is how far apart nodes are; not their size
	void draw(int scale);
	//Creates all nodes and populates list
	void createGraph(int size);

	/*These are all the functions I needed to make my A* application
		These ARE NOT NEEDED for the graph to function but will be needed for A*
		to be used with this graph*/
		//Finds and returns a nodes position within the graph
	Node* findNode(Vector2 pos);
	//Finds manhattan distance between two nodes. This is what i used for my H score. Optional if you dont need an H score
	int findManhattan(Node*, Node*);
	//This marks all nodes in the path as a PathNode. I just use this to color them correctly when I draw. 
	void reconstructPath(Node*, Node*);
	// Returns whether or not a node is inside a list. It takes in a pointer to a list. I made it this way in case I wanted to change the list in the function.
	//To make a pointer to a list do this: std::vector<Node*>* listPtr = &someList;
	bool containsNode(std::vector<Node*>*, Node*);
	//Trys to remove a node from a list. The first argument is a pointer to the list you want to remove from. The second is the node you want to remove.
	void removeNode(std::vector<Node*>*, Node*);
	//Sorts a list based on the f score of the nodes
	void sortNodeList(std::vector<Node*>*);
	//Finds a path from the starting position given to the ending position given
	void AStarSearch(Vector2 startPos, Vector2 endPos);
};