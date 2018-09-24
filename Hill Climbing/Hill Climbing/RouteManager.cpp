#include "RouteManager.h"

RouteManager::RouteManager(int InitNumNodes, int InitWidth, int InitHeight, int InitMaxIters, float InitTemp, float InitCoolingRate)
{
	NumNodes = InitNumNodes;
	GridWidth = InitWidth;
	GridHeight = InitHeight;
	MaxIters = InitMaxIters;
	AnnealTemp = InitTemp;
	CoolingRate = InitCoolingRate;

	BaseRoute = new Route(NumNodes, GridWidth, GridHeight);
}

RouteManager::~RouteManager()
{
}

Route * RouteManager::GetBaseRoute()
{
	return BaseRoute;
}

Route * RouteManager::GetBestRouteHC()
{
	return BestRouteHC;
}

Route * RouteManager::GetBestRouteSA()
{
	return BestRouteSA;
}

Route * RouteManager::GetTempRoute()
{
	return TempRoute;
}

int RouteManager::GetNumNodes()
{
	return NumNodes;
}

int RouteManager::GetGridWidth()
{
	return GridWidth;
}

int RouteManager::GetGridHeight()
{
	return GridHeight;
}

int RouteManager::GetMaxIters()
{
	return MaxIters;
}

float RouteManager::GetAnnealTemp()
{
	return AnnealTemp;
}

float RouteManager::GetCoolingRate()
{
	return CoolingRate;
}

void RouteManager::SetMaxIters(int NewMax)
{
	MaxIters = NewMax;
}

void RouteManager::SetAnnealTemp(float NewTemp)
{
	AnnealTemp = NewTemp;
}

void RouteManager::SetCoolingRate(float NewRate)
{
	CoolingRate = NewRate;
}



void RouteManager::HillClimbing()
{
	cout << endl << "---------- Solving Via Hill Climbing ----------" << endl;
	BestRouteHC = BaseRoute;
	for (int i = 0; i < MaxIters; i++)
	{
		TempRoute = new Route(BaseRoute);
		if (TempRoute->GetDistance() < BestRouteHC->GetDistance())
		{
			BestRouteHC = TempRoute;
		}
	}

	cout << "     Best Node ";
	BestRouteHC->PrintInfo();
	cout << endl;
}

void RouteManager::SimulatedAnnealing()
{
	cout << endl << "---------- Solving Via Simulated Annealing ----------" << endl;
	float Temperature = AnnealTemp;
	
	BestRouteSA = BaseRoute;
	while (Temperature > 1)
	{
		TempRoute = new Route(BaseRoute);
		if (TempRoute->GetDistance() < BestRouteSA->GetDistance())
		{
			BestRouteSA = TempRoute;
		}
		else if (TempRoute->GetDistance() - Temperature < BestRouteSA->GetDistance())
		{
			BestRouteSA = TempRoute;
		}
		Temperature -= CoolingRate;
	}
	cout << "     Best Node ";
	BestRouteSA->PrintInfo();
	cout << endl;
}

void RouteManager::PrintMenu()
{
	cout << "     Base Node ";
	BaseRoute->PrintInfo();
	cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "     Number of Nodes: " << NumNodes << "     Grid Size : " << GridHeight << "x" << GridWidth << endl;
	cout << "     Maximum HillCliming Iterations: " << MaxIters << "     Starting Temerature: " << AnnealTemp << "     Cooling Rate: " << CoolingRate << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                   1) Set Maximum HillCliming Iterations     2) Set Start Annealing Temperature     3) Set Cooling Rate" << endl;
	cout << "                   4) Start Hill Climbing                    5) Start Simulated Annealing           6) Exit" << endl;
	cout << "     Select Option : ";

}
