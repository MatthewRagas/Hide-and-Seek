#pragma once
#include "Connections.h"
#include <vector>

class Node
{
public:
	Node() {}
	~Node() {}
	Node(Vector2 newposition) { position = newposition; }
	Vector2 position;
	float gScore = 0;
	float fScore = 0;
	float hScore = 0;
	bool isStartNode;
	bool isGoalNode;
	bool isPathNode;
	Node*parent = nullptr;
	std::vector<Connections*> connections;
	void Draw(float scale);
};

