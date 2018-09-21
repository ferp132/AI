#pragma once

#include <list>
#include "Node.h"
#include "Coordinate.h"

class Grid {

private:

	std::list<Node*> ToCheck;			//a list of the remaining nodes to check
	Node* Nodes;						//All the nodes that make up the grid
	Node* StartNode;					//Node to begin Pathfinding From
	Node* EndNode;						//Destination Node

	int GridHeight;						//Height of the grid
	int GridWidth;						//Width of the grid

public:

	Grid(int InitHeight, int InitWidth);
	~Grid();

	void CheckNode(Node* Checking);		//Checks all the nbeightbours of this node
//	void UpdateNode(Node* ToUpdate);	//Updates the nodes Parent, LocalValue & GlobalValue
	void DrawGrid();					//Draws the grid in the console
	void FindPath();					//Finds the optimal path from the start node to the end node

	void SetStart(Coord NewStart);		//Sets the new start node
	void SetEnd	 (Coord NewEnd);		//Sets a new end node
	void SetObs	 (Coord NewObstacle);	//Sets a node in the grid to an obstacle
};