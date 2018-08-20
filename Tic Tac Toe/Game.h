#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#include "Board.h"
#include "Player.h"
#include "Node.h"
#include "MiniMaxTree.h"
class Game
{
public: 
	Game();
	~Game();

	MiniMaxTree MyTree;
	Board GameBoard;
	void PickTile();
	void PlayTurn();
	void GameLoop();
	bool CheckWin();
	void ClearScreen();
	void AIPickTile();
	void RandomPickTile();
private:
	bool Difficulty;	//For the AI, false = easy/random, true = hard/smart
	bool GameMode;		//false = Player vs Player, true = Player vs AI
	bool PlayerTurn;	//false = X (Player 1, Who Starts) true = O (Player 2 or AI)
	bool GameOver;
	unsigned int MaxTurns;
	unsigned int TurnsTaken;
	unsigned int Winner;
};