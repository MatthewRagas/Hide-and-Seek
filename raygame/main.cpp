/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "seekBehavior.h"
#include "WanderBehavior.h"
#include "Flee.h"
#include "Decision.h"
#include "DecisionTreeBehavior.h"
#include "BehaviorDecision.h"
#include "BooleanDecision.h"
#include "seekBehavior.h"
#include "WithinRangeCondition.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1920;
	int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	//Create Player
	Agent* player = new Agent();
	player->setPosition(Vector2{ 910.0f, 540.0f });
	player->setSpeed(100.0f);

	//Create enemy
	Agent* enemy = new Agent();
	enemy->setPosition(Vector2{ 450.0f, 225.0f });
	enemy->setSpeed(50.0f);

	Agent* enemy_1 = new Agent();
	enemy_1->setPosition(Vector2{ 1500.0f, 200.0f });
	enemy_1->setSpeed(50.0f);

	//Create and add behaviors
	/*WanderBehavior* wander = new WanderBehavior();
	seekBehavior* seek = new seekBehavior();
	seek->setTarget(player);
	Flee* flee = new Flee();
	flee->setTarget(enemy_1);*/

	/*player->addBehavior(flee);
	enemy->addBehavior(seek);
	enemy_1->addBehavior(wander);*/

	//--------------------------------------------------------------
	//Leaves of Decision Tree
	WanderBehavior* wander = new WanderBehavior();
	BehaviorDecision* wanderDecision = new BehaviorDecision(wander);

	seekBehavior* seek = new seekBehavior();
	seek->setTarget(player);
	BehaviorDecision* seekDecision = new BehaviorDecision(seek);

	Flee* flee = new Flee();
	flee->setTarget(enemy);
	BehaviorDecision* fleeDecision = new BehaviorDecision(flee);
	//------------------------------------------------------------
	//Branches
	WithinRangeCondition* canSeeCondition = new WithinRangeCondition(player, 50);
	BooleanDecision* canSeeDecision = new BooleanDecision(fleeDecision, wanderDecision, canSeeCondition);
	
	WithinRangeCondition* canHearCondition = new WithinRangeCondition(enemy, 50);
	BooleanDecision* canHearDecision = new BooleanDecision(seekDecision, wanderDecision, canHearCondition);
	//------------------------------------------------------------
	//adding Decision tree
	DecisionTreeBehavior* enemyDecisionTree = new DecisionTreeBehavior(canHearDecision);
	DecisionTreeBehavior* playerDecisionTree = new DecisionTreeBehavior(canSeeDecision);

	player->addBehavior(playerDecisionTree);
	enemy->addBehavior(enemyDecisionTree);
	enemy_1->addBehavior(enemyDecisionTree);



	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here

		float deltaTime = GetFrameTime();

		player->update(deltaTime);
		enemy->update(deltaTime);
		enemy_1->update(deltaTime);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		enemy->draw();
		enemy_1->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}