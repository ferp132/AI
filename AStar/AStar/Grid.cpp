#include <iostream>
#include "Grid.h"

using namespace std;

Grid::Grid(int InitHeight, int InitWidth)
{
	GridHeight = InitHeight;
	GridWidth = InitWidth;

	Nodes = new Node[GridHeight * GridWidth];

	Node CN;																										//CurrentNode

	for (int y = 0; y < GridHeight; y++)
	{
		for (int x = 0; x < GridWidth; x++)
		{
			CN = Nodes[y * GridWidth + x];

			CN.NodePos.xPos	= x;
			CN.NodePos.yPos	= y;
			CN.GlobalValue	= INT_MAX;
			CN.LocalValue	= INT_MAX;
			CN.Obstacle		= false;
			CN.Visited		= false;
			CN.Parent		= nullptr;
			CN.Symbol		= '0';

			if (y > 0)			CN.Neighbours.push_back(&Nodes[(y - 1) * GridWidth + x]);
			if (y < GridHeight) CN.Neighbours.push_back(&Nodes[(y + 1) * GridWidth + x]);
			if (x > 0)			CN.Neighbours.push_back(&Nodes[y * GridWidth + (x - 1)]);
			if (x < GridWidth)	CN.Neighbours.push_back(&Nodes[y * GridWidth + (x + 1)]);
		}
	}

	StartNode = nullptr;
	EndNode	  = nullptr;
}

Grid::~Grid()
{
	delete[] Nodes;
}

void Grid::CheckNode(Node* Checking)
{
	Node* CNb;																								//Current Neighbour
	for (int i = 0; i < Checking->Neighbours.size(); i++)
	{
		CNb = Checking->Neighbours.at(i);

		if (CNb->Visited == false) ToCheck.push_back(CNb);	//if the current neighbour has not been visited, add it to the list of nodes to be checked
		if (Checking->LocalValue < Checking->Neighbours.at(i)->LocalValue + 1)
		{
			CNb->Parent = Checking;
			CNb->LocalValue = Checking->LocalValue + 1;
			CNb->GlobalValue = CNb->LocalValue; // + Find Distance between this and the end node using pythagoras
		}
	}

	Checking->Visited = true;
	ToCheck.pop_front();
	return;
}

void Grid::DrawGrid()
{
	for (int y = 0; y < GridHeight; y++)
	{
		for (int x = 0; x < GridWidth; x++)
		{
			cout << " " <<  Nodes[y * GridWidth + x].Symbol << " ";
		}
			cout << endl;
	}
}

void Grid::FindPath()
{
	if (StartNode == nullptr || EndNode == nullptr) return; //will not try to run this function if there is no start or end node

	ToCheck.push_back(StartNode);							//Adds the start node to the list, the list should be empty besides this node
	//StartNode->GlobalValue = Hueristic(StartNode);
	StartNode->LocalValue = 0;

	while (!ToCheck.empty())								//Do this until there are no more nodes to check
	{
		ToCheck.sort([](const Node* lhs, const Node* rhs) {return lhs->GlobalValue < rhs->GlobalValue; });	//Sort the list

		CheckNode(ToCheck.front());
	}

	Node* PathFinder = EndNode;

	while (PathFinder->Parent != nullptr)
	{
		if (PathFinder->Symbol != 'S' || PathFinder->Symbol != 'E') PathFinder->Symbol = 'P';
		PathFinder = PathFinder->Parent;
	}
}

void Grid::SetStart(Coord NewStart)
{
	if (StartNode != nullptr) StartNode->Symbol = '0';

	StartNode = &Nodes[NewStart.yPos * GridWidth + NewStart.xPos];
	StartNode->Symbol = 'S';
}

void Grid::SetEnd(Coord NewEnd)
{
	if (EndNode != nullptr) EndNode->Symbol = '0';

	EndNode = &Nodes[NewEnd.yPos * GridWidth + NewEnd.xPos];
	EndNode->Symbol = 'E';
}

void Grid::SetObs(Coord NewObstacle)
{
	Nodes[NewObstacle.yPos * GridWidth + NewObstacle.xPos].Obstacle = !Nodes[NewObstacle.yPos * GridWidth + NewObstacle.xPos].Obstacle;
}
