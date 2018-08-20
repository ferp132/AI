#pragma once
#include "Board.h"
#include <algorithm>
#include <vector>
#include <array>

class Node
{
public:
	Node(Node* MyParent);
	Node (Board RootBoardState, int RootDepth, bool RootDifficulty);
	~Node();

	void SetMinMax(bool NewMinMax);
	void SetDepth (int NewDepth);
	void SetValue (int NewValue);
	void SetAlpha (int NewAlpha);
	void SetBeta  (int NewBeta);
	void SetParent(Node* NewParent);
	void SetChild (Node* NewChild, unsigned int WhichChild);

	bool   GetDifficulty();
	bool   GetMinMax();
	int    GetDepth ();
	int    GetValue ();
	int    GetAlpha ();
	int	   GetBeta  ();
	Node*  GetParent();
	vector<Node*> GetChildren();
	Node*  GetChild (int WhichChild);
	Board* GetBoardState();
	Board GetBoard();

	Node* CreateChild();
	void CreateLayer();

	int CheckStateEasy();
	int CheckStateHard();

private:
	bool   Difficulty;
	bool   MinMax; //1 = Max, 0 = Min
	int	   Depth;
	int    Value;
	int    Alpha;
	int	   Beta;
	Node*  Parent;
	vector<Node*> Children;

	Board BoardState;
};