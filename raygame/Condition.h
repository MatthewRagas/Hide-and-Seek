#pragma once
#include "Agent.h"

/*	Condition
Conditions allow us to test the success of decisions and
transitions. As a pure virtual class, classes inherit from
Condition and implement the test function to decide the
result.
*/

class Condition
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;
};

