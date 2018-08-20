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
			if (BoardArray[y][x] == 0)
			{
				cout << " ";
			}
			else if (BoardArray[y][x] == X)
			{
				cout << "X" ;
			}
			else
			{
				cout << "O";
			}
			cout << " | ";
		}
		cout << endl << " -------------" << endl;
	}
	cout << endl;
}

bool Board::CheckWin(int Symbol)
{
		//Winning Conditions;
		bool Horz1 = (this->GetTile(0, 0) == Symbol) && (this->GetTile(0, 1) == Symbol) && (this->GetTile(0, 2) == Symbol); //First Row
		bool Horz2 = (this->GetTile(1, 0) == Symbol) && (this->GetTile(1, 1) == Symbol) && (this->GetTile(1, 2) == Symbol); //Second Row	
		bool Horz3 = (this->GetTile(2, 0) == Symbol) && (this->GetTile(2, 1) == Symbol) && (this->GetTile(2, 2) == Symbol); //Third Row
		bool Vert1 = (this->GetTile(0, 0) == Symbol) && (this->GetTile(1, 0) == Symbol) && (this->GetTile(2, 0) == Symbol); //First Collumn
		bool Vert2 = (this->GetTile(0, 1) == Symbol) && (this->GetTile(1, 1) == Symbol) && (this->GetTile(2, 1) == Symbol); //Second Collumn
		bool Vert3 = (this->GetTile(0, 2) == Symbol) && (this->GetTile(1, 2) == Symbol) && (this->GetTile(2, 2) == Symbol); //Third Collumn
		bool Diag1 = (this->GetTile(0, 0) == Symbol) && (this->GetTile(1, 1) == Symbol) && (this->GetTile(2, 2) == Symbol); //Diagonal From Top Left
		bool Diag2 = (this->GetTile(0, 2) == Symbol) && (this->GetTile(1, 1) == Symbol) && (this->GetTile(2, 0) == Symbol); //Diagonal From Top Right

		if (Horz1 || Horz2 || Horz3 || Vert1 || Vert2 || Vert3 || Diag1 || Diag2)
		{
			return true;
		}

		return false;
}

void Board::SetTile(int Symbol, int xLocation, int yLocation)
{
	BoardArray[yLocation][xLocation] = Symbol;

}

int Board::GetTile(int yLocation, int xLocation)
{
	return BoardArray[yLocation][xLocation];
}
