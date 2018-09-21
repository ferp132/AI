#include <iostream>

#include "Grid.h"
#include "Coordinate.h"

using namespace std;

int main(void)
{
	Grid MainGrid(5, 5);
	Coord Start = { 2, 1 };
	Coord End = { 4, 3 };

	MainGrid.DrawGrid();

	int wait;
	cin >> wait;

	MainGrid.SetStart(Start);
	MainGrid.SetEnd(End);
	MainGrid.DrawGrid();

	cin >> wait;

	Start = { 4, 4 };
	End = { 2,2 };

	MainGrid.SetStart(Start);
	MainGrid.SetEnd(End);
	MainGrid.DrawGrid();

	cin >> wait;
}