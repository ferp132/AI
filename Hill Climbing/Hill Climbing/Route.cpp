#include "Route.h"

Route::Route(int InitNumNodes, int InitWidth, int InitHeight)
{
	NumNodes = InitNumNodes;
	GridWidth = InitWidth;
	GridHeight = InitHeight;

	Node* NodePointer;
	float NodexPos;
	float NodeyPos;


	for (int i = 0; i < NumNodes; i++)
	{
		
		NodexPos = (float)(rand() % GridWidth);
		NodeyPos = (float)(rand() % GridHeight);
		NodePointer = new Node(i,NodexPos, NodeyPos);

		NodeList.push_back(*NodePointer);
	}

	FindDistance();
}

Route::Route(Route * CopyRoute)
{
	NodeList = CopyRoute->NodeList;
	NumNodes = CopyRoute->GetNumNodes();

	SwapRandomNodes();
	FindDistance();
}

Route::~Route()
{
	for (unsigned int i = 0; i < NodeList.size(); i++)
	{
		delete &NodeList.at(i);
	}
}

float Route::GetDistance()
{
	return Distance;
}

int Route::GetNumNodes()
{
	return NumNodes;
}

void Route::FindDistance()
{
	float TotalDistance = 0;

	for (unsigned int i = 0; i < NodeList.size() - 1; i++)
	{
		TotalDistance += DistanceBetween(&NodeList.at(i), &NodeList.at(i + 1));
	}

	Distance = TotalDistance;
}

float Route::DistanceBetween(Node* a, Node* b)
{
	float xLength = b->GetxPos() - a->GetxPos();
	float yLength = b->GetyPos() - a->GetyPos();

	return sqrtf(xLength * xLength + yLength * yLength);
}

void Route::SwapRandomNodes()
{
	int RandElement1 = rand() % NumNodes;
	int RandElement2 = rand() % NumNodes;
	while(RandElement1 == RandElement2) RandElement2 = rand() % NumNodes;

	iter_swap(NodeList.begin() + RandElement1, NodeList.begin() + RandElement2);
}

void Route::PrintInfo()
{
	cout << "Configuration: ";
	for (unsigned int i = 0; i < NodeList.size(); i++)
	{
		cout << NodeList.at(i).GetIndex() << "(" << NodeList.at(i).GetxPos() << ", " << NodeList.at(i).GetyPos() << ")   ";
	}
	cout << endl << "     Total distance in this configuration: " << Distance << endl;

	return;
}


