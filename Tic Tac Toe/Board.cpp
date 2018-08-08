#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::DrawBoard()
{
	cout << " -------------" << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << " | ";
		for (int x = 0; x < 3; x++)
		{
			if (BoardArray[x][y] == 0)
			{
				cout << " ";
			}
			else
			{
				cout << BoardArray[x][y];
			}
			cout << " | ";
		}
		cout << endl << " -------------" << endl;
	}
}

void Board::CheckWin(int Symbol, int xLocation, int yLocation)
{
}

void Board::SetTile(int Symbol, int xLocation, int yLocation)
{
}

int Board::GetTile(int xLocation, int yLocation)
{
	return 0;
}
