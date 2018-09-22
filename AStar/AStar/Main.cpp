#include <iostream>
#include <stdlib.h>
#include "Grid.h"
#include "Coordinate.h"

using namespace std;

int main(void)
{
	int wait;
	Coord GridSize;
	int MenuChoice;
	Coord NodeChoice;
	bool Exit = false;

	cout << "Welcome to Louis' A* Algorithm" << endl;
	cout << "Select the size of your grid: " << endl << endl;
	cout << "Width: ";
	cin >> GridSize.xPos;
	cout << "Height: ";
	cin >> GridSize.yPos;

	Grid MainGrid(GridSize);

	while (!Exit)
	{
		NodeChoice = { -1, -1 };
		MainGrid.DrawGrid();
		MainGrid.DrawMenu();
		
		cin >> MenuChoice;
		MainGrid.DrawGrid();

		switch (MenuChoice)
		{
		case 1: 
		{
			MainGrid.FindPath();
			break;
		}
		case 2:
		{
			cout << "Setting Obstacle:" << endl;
			cout << "X Position: ";
			cin >> NodeChoice.xPos;
			cout << "Y Position: ";
			cin >> NodeChoice.yPos;
			MainGrid.SetObs(NodeChoice);
			break;
		}
		case 3:
		{
			cout << "Setting Start Node:" << endl;
			cout << "X Position: ";
			cin >> NodeChoice.xPos;
			cout << "Y Position: ";
			cin >> NodeChoice.yPos;
			MainGrid.SetStart(NodeChoice);
			break;
		}
		case 4:
		{
			cout << "Setting End Node:" << endl;
			cout << "X Position: ";
			cin >> NodeChoice.xPos;
			cout << "Y Position: ";
			cin >> NodeChoice.yPos;
			MainGrid.SetEnd(NodeChoice);
			break;
		}
		case 5:
		{
			MainGrid.ResetGrid();
			break;
		}
		case 6:
		{
			Exit = true;
			break;
		}
		}
	}
}