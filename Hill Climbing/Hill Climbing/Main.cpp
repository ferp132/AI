#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "RouteManager.h"
#include "Route.h"

using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));
	int GridWidth = 20;
	int GridHeight = 20;
	int NumNodes = 10;
	int MaxIters = 10;
	float AnnealTemp = 100;
	float CoolRate = 0.2;
	int MenuOption = 0;
	bool exit = 0;

	cout << "Welcome to Louis' Hill Climbing & Simulated Annealing Simulator" << endl;
	cout << "This Program attempts to solve the travelling salesman problem" << endl;
	cout << "It will generate a number of nodes upon a grid and will attempt to find the shortest distance you can travel while visiting all nodes" << endl << endl;
	cout << "Current Number of Nodes: " << NumNodes << endl << "Please enter how many nodes to generate: ";
	cin >> NumNodes;
	cout << endl << "Current Grid Size: " << GridHeight << " x " << GridWidth << endl << "Please Enter your desired grid size: ";
	cin >> GridHeight;
	system("CLS");

	RouteManager MainManager(NumNodes, GridHeight, GridHeight, MaxIters, AnnealTemp, CoolRate);

	while (!exit)
	{
		MainManager.PrintMenu();
		cin >> MenuOption;
		if (MenuOption == 1)
		{
			cout << endl << "Setting Max Iterations: ";
			cin >> MaxIters;
			MainManager.SetMaxIters(MaxIters);
			system("CLS");
		}
		else if (MenuOption == 2)
		{
			cout << endl << "Setting Base Temperature: ";
			cin >> AnnealTemp;
			MainManager.SetAnnealTemp(AnnealTemp);
			system("CLS");
		}
		else if (MenuOption == 3)
		{
			cout << endl << "Setting Cooling Rate: ";
			cin >> CoolRate;
			MainManager.SetCoolingRate(CoolRate);
			system("CLS");
		}
		else if (MenuOption == 4)
		{
			system("CLS");
			MainManager.HillClimbing();
		}
		else if (MenuOption == 5)
		{
			system("CLS");
			MainManager.SimulatedAnnealing();
		}
		else if (MenuOption == 6)
		{
			exit = true;
		}


	}


	cin.ignore();
}