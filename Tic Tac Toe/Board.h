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
	int BoardArray[3][3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
public:
	Board();
	~Board();

	void DrawBoard();
	void CheckWin(int Symbol, int xLocation, int yLocation);
	void SetTile(int Symbol, int xLocation, int yLocation);

	int GetTile(int xLocation, int yLocation);

};

#endif