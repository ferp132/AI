#pragma once
#ifndef _BOARD_H__
#define _BOARD_H__

#include <iostream>

using namespace std;

enum Symbols
{
	X = 1,
	O = 2,
};

class Board {
private:
	//			  [y][x]
	int BoardArray[3][3] = {{ 0, 0, 0 }, 
							{ 0, 0, 0 }, 
							{ 0, 0, 0 }};
public:
	Board();
	~Board();

	void DrawBoard();
	
	bool CheckStateHard(int Symbol);
	void SetTile(int Symbol, int yLocation, int xLocation);

	int GetTile(int yLocation, int xLocation);

};

#endif