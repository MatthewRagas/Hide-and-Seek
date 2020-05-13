#pragma once
#include "raylib.h"

struct Node;

class Connections
{
public:
	Connections();
	Connections(Node*,float);
	Node* target;
	float cost;
	Color drawColor;
	void Draw(Vector2 startPos, float scale);
};

