#pragma once
#include <vector>
#include "Coordinate.h"

struct Node
{
	Node* Parent;					//Pointer to the current parent of this node
	std::vector<Node*> Neighbours;	//List of all the neighbours of this node

	float GlobalValue;				//Current heuristic for the distance from this node to the end node
	float LocalValue;				//Steps taken to get to this node

	Coord NodePos;					//Position of the node in the grid

	bool Visited;					//Has this node been visited and had it's neighbours checked?
	bool Obstacle;					//Is this a node that cant be traversed?

	char Symbol;					//The Character that will be displayed onscreen when this node is drawn
};