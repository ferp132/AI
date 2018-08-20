#pragma once
#include "Board.h"

class Node
{
public:
	Node(Node* MyParent);
	Node (Board RootBoardState, int RootDepth);
	~Node();

	void SetMinMax(bool NewMinMax);
	void SetDepth (int NewDepth);
	void SetValue (int NewValue);
	void SetAlpha (int NewAlpha);
	void SetBeta  (int NewBeta);
	void SetParent(Node* NewParent);
	void SetChild (Node* NewChild, unsigned int WhichChild);

	bool   GetMinMax();
	int    GetDepth ();
	int    GetValue ();
	int    GetAlpha ();
	int	   GetBeta  ();
	Node*  GetParent();
	Node*  GetChild (unsigned int WhichChild);
	Board* GetBoardState();

	Node* CreateChild(unsigned int ChildNumber);

private:
	bool   MinMax; //1 = Max, 0 = Min
	int	   Depth;
	int    Value;
	int    Alpha;
	int	   Beta;
	Node*  Parent;
	Node** Children;

	Board BoardState;
};