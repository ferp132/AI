#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void PickTile();
private: 
	Board * GameBoard;
};