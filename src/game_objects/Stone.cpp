/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	The Stone Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Stone.h"

/***************************************************************************************************
**	default constructor for Stone
***************************************************************************************************/
Stone::Stone() : Object('O', "Colored", 2, 2, "Stone")
{
	color = "white";
	weight = 10;
}

/***************************************************************************************************
**	constructor for Stone initializing rowPos and colPos
***************************************************************************************************/
Stone::Stone(int row, int col, string c) : Object('O', "Colored", row, col, "Stone")
{
	color = c;
	weight = 10;
}

/***************************************************************************************************
**	deconstructor for Stone
***************************************************************************************************/
Stone::~Stone()
{
}

/***************************************************************************************************
**	Sets up Stone
***************************************************************************************************/
void Stone::setStone(int row, int col, string c)
{
	this->rowPos = row;
	this->colPos = col;
	this->color = c;
	this->type = "Stone";
}

/***************************************************************************************************
**	returns the weight of the object
***************************************************************************************************/
int Stone::getWeight()
{
	return weight;
}

/***************************************************************************************************
**	returns the name of the Object
***************************************************************************************************/
string Stone::getName()
{
	return color;
}

/***************************************************************************************************
**	returns the weight of the object
***************************************************************************************************/
void Stone::setWeight(int w)
{
	weight = w;
}