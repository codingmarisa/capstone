/*............................................
 @file Trap.cpp
 @date 1/30/19

............................................*/
#include "Trap.hpp"

/*............................................
CONSTRUCTOR/DESTRUCTORS

............................................*/

Trap::Trap()
{
	name = "Trap";
	type = "trap";
	weight = 2;
	damage = 6;
	symbol = "☼";
	color = COLOR_RED;
	description = "Damages the player for 6 HP";
}

Trap::Trap(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "Trap";
	type = "trap";
	weight = 2;
	damage = 6;
	symbol = "☼";
	color = COLOR_RED;
	description = "Damages the player for 6 HP";
}

Trap::~Trap()
{
}
/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/

void Trap::triggerItemActions(char direction)
{
	//filler for later use  (laying a trap?)
}
