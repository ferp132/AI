#pragma once
#include <windows.h>
#include "Node.h"
#include "Route.h"
class RouteManager
{
public:
	RouteManager(int InitNumNodes, int InitWidth, int InitHeight, int InitMaxIters, float InitTemp, float InitCoolingRate);
	~RouteManager();

	Route * GetBaseRoute();
	Route * GetBestRouteHC();
	Route * GetBestRouteSA();
	Route * GetTempRoute();
	int GetNumNodes();
	int GetGridWidth();
	int GetGridHeight();
	int GetMaxIters();
	float GetAnnealTemp();
	float GetCoolingRate();

	void SetMaxIters(int NewMax);
	void SetAnnealTemp(float NewTemp);
	void SetCoolingRate(float NewRate);

	void HillClimbing();
	void SimulatedAnnealing();
	void PrintMenu();

private:

	Route * BaseRoute;
	Route * BestRouteHC;
	Route * BestRouteSA;
	Route * TempRoute;
	int NumNodes;
	int GridWidth;
	int GridHeight;
	int MaxIters;
	float AnnealTemp;
	float CoolingRate;
};