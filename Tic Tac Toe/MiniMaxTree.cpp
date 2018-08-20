#include "MiniMaxTree.h"

MiniMaxTree::MiniMaxTree()
{
	CurrentRoot = nullptr;
	MaxNode = nullptr;
}

MiniMaxTree::~MiniMaxTree()
{
}

Board MiniMaxTree::InitMiniMax(Board InitBoardState, unsigned int InitDepth, bool InitDifficulty)
{
	int initMax;
	int MaxTry;

	CurrentRoot = new Node(InitBoardState, InitDepth, InitDifficulty);
//	Node MaxNode = CurrentRoot;
	CurrentRoot->CreateLayer();
	initMax = -2;
	for (int AllChildren = 1; AllChildren < CurrentRoot->GetDepth(); AllChildren++)
	{
		MaxTry = MiniMax(CurrentRoot->GetChild(AllChildren));
		if (MaxTry > initMax)
		{
			MaxNode = CurrentRoot->GetChild(AllChildren);
			initMax = MaxTry;
		}
	}
	
	return MaxNode->GetBoard();
}

int MiniMaxTree::MiniMax(Node * N)
{
			//If this is a leaf node, return the value
	if (N->GetDepth() == 0)
	{
		return N->GetValue();
	}
	else 
	{		//Create The Successors to N
		N->CreateLayer();
		if (N->GetMinMax())
		{	//If this is a max node Then return the max of the Successors
			int Max = -1000;
			for (int AllChildren = 0; AllChildren < size(N->GetChildren()) ; AllChildren++)
			{
				if (N->GetChild(AllChildren) != nullptr)
				{
					Max = max(Max, MiniMax(N->GetChild(AllChildren)));
				}
			}
			return Max;
		}
		else
		{	//return the min of the Successors
			int Min = 1000;
			for (int AllChildren = 0; AllChildren <  size(N->GetChildren()); AllChildren++)
			{
				if (N->GetChild(AllChildren) != nullptr)
				{
					Min = min(Min, MiniMax(N->GetChild(AllChildren)));
				}
			}
			return Min;
		}

	}
}

