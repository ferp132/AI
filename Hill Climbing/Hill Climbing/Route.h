#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#include "Node.h"

using namespace std;

class Route
{
public:

	Route(int InitNumNodes, int InitWidth, int InitHeight);
	Route(Route* CopyRoute);
	~Route();

	vector<Node> NodeList;
	float GetDistance();
	int GetNumNodes();

	void FindDistance();
	float DistanceBetween(Node* a, Node* b);
	void SwapRandomNodes();
	void PrintInfo();

private:


	float Distance;
	int NumNodes;
	int GridWidth;
	int GridHeight;
};