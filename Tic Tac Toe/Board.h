#pragma once
#ifndef _BOARD_H__
#define _BOARD_H__

enum Symbols
{
	X = 1,
	O = 2,
};

class Board {
private:
	int Tiles[3][3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
public:
	Board();

	void CheckWin(int Symbol, int Location);
	void SetTile(int Symbol, int Location);

	int GetTile(int Location);

};

#endif