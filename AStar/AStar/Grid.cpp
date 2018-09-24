#include <iostream>
#include <stdlib.h>
#include "Grid.h"

using namespace std;

Grid::Grid(Coord InitGridSize)
{
	GridHeight = InitGridSize.yPos;
	GridWidth = InitGridSize.xPos;

	Nodes = new Node[GridHeight * GridWidth];

	Node* CN;																										//CurrentNode

	for (int y = 0; y < GridHeight; y++)
	{
		for (int x = 0; x < GridWidth; x++)
		{
			CN = &Nodes[y * GridWidth + x];

			CN->NodePos.xPos = x;
			CN->NodePos.yPos = y;
			CN->GlobalValue	 = INT_MAX;
			CN->LocalValue	 = INT_MAX;
			CN->Obstacle	 = false;
			CN->Visited		 = false;
			CN->Parent		 = nullptr;
			CN->Symbol		 = '0';

			if (y > 0)				CN->Neighbours.push_back(&Nodes[(y - 1) * GridWidth + x]);
			if (y < GridHeight - 1) CN->Neighbours.push_back(&Nodes[(y + 1) * GridWidth + x]);
			if (x > 0)				CN->Neighbours.push_back(&Nodes[y * GridWidth + (x - 1)]);
			if (x < GridWidth - 1)	CN->Neighbours.push_back(&Nodes[y * GridWidth + (x + 1)]);
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
		CNb = Checking->Neighbours.at(i);																	//Set Current Neighbour
		if (CNb->Obstacle) continue;																		//if this neighbour is an obstacle, skip it & continue to the next one.

		if (CNb->Visited == false)
		{
			ToCheck.push_back(CNb);																			//if the current neighbour has not been visited, add it to the list of nodes to be checked
			CNb->Visited = true;
			if (CNb != EndNode) CNb->Symbol = 'V';
		}
		
		if (Checking->LocalValue < Checking->Neighbours.at(i)->LocalValue + 1)
		{
			CNb->Parent = Checking;
			CNb->LocalValue = Checking->LocalValue + 1;
			if (CNb == EndNode) CNb->GlobalValue = 0;
			else				CNb->GlobalValue = CNb->LocalValue + DistanceToEnd(CNb); 
		}
	}
	ToCheck.pop_front();
	DrawGrid();

	return;
}

void Grid::FindPath()
{
	if (StartNode == nullptr || EndNode == nullptr) return; //will not try to run this function if there is no start or end node

	ToCheck.push_back(StartNode);							//Adds the start node to the list, the list should be empty besides this node
	StartNode->GlobalValue = DistanceToEnd(StartNode);
	StartNode->LocalValue = 0;
	StartNode->Visited = true;

	while (!ToCheck.empty())								//Do this until there are no more nodes to check
	{
		ToCheck.sort([](const Node* lhs, const Node* rhs) {return lhs->GlobalValue < rhs->GlobalValue; });	//Sort the list

		CheckNode(ToCheck.front());
	}

	Node* PathFinder = EndNode;

	while (PathFinder->Parent != nullptr)
	{
		if (PathFinder != StartNode && PathFinder != EndNode) PathFinder->Symbol = 'P';
		PathFinder = PathFinder->Parent;
	}
}

void Grid::DrawGrid()
{
	system("CLS");
	cout << endl << "-----------------------------------------------------------------------------------------------------" << endl;
	for (int y = 0; y < GridHeight; y++)
	{
		for (int i = 0; i < 40 - GridWidth; i++) cout << " ";
		for (int x = 0; x < GridWidth; x++)
		{
			cout << Nodes[y * GridWidth + x].Symbol << " ";
		}
		cout << endl;
	}
	cout << endl << "0 = Empty Node     S = Start Node     E = End Node     V = Visited Node     P = Path     X = Obstacle" << endl;
	cout		 << "-----------------------------------------------------------------------------------------------------" << endl;
}

void Grid::DrawMenu()
{
	cout << "          Select Option: " << endl;
	cout << "     1) Find Path     2) Set Obstacle     3) Set Start" <<endl;
	cout << "     4) Set End       5) Reset Path       6) Exit          " << endl;
	cout << "          ";
}

float Grid::DistanceToEnd(Node * Checking)
{
	float xLength = (float)(Checking->NodePos.xPos - EndNode->NodePos.xPos);
	float yHeight = (float)(Checking->NodePos.yPos - EndNode->NodePos.yPos);

	return sqrtf(xLength * xLength + yHeight * yHeight);
}

void Grid::ResetGrid()
{
	for (int y = 0; y < GridHeight; y++)
	{
		for (int x = 0; x < GridWidth; x++)
		{
			Nodes[y * GridWidth + x].Parent										   = nullptr;
			Nodes[y * GridWidth + x].GlobalValue								   = INT_MAX;
			Nodes[y * GridWidth + x].LocalValue									   = INT_MAX;
			if(!Nodes[y * GridWidth + x].Obstacle) Nodes[y * GridWidth + x].Symbol = '0';
			Nodes[y * GridWidth + x].Visited									   = false;
		}
	}
	StartNode->Symbol	= 'S';
	EndNode->Symbol		= 'E';
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
	Nodes[NewObstacle.yPos * GridWidth + NewObstacle.xPos].Symbol = 'X';
}
