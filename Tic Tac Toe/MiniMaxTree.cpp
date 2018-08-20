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
	CurrentRoot = new Node(InitBoardState, InitDepth, InitDifficulty);
	CurrentRoot->SetValue(MiniMax(CurrentRoot));

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
			for (int AllChildren = 0; AllChildren < size(N->GetChildren()); AllChildren++)
			{
				Max = max(Max, (MiniMax(N->GetChild(AllChildren))));
			}

			if (N->GetValue() == Max)
			{
				MaxNode = N;
			}
			else N->SetValue(Max);
			return Max;
		}
		else
		{	//return the min of the Successors
			int Min = 1000;
			for (int AllChildren = 0; AllChildren < size(N->GetChildren()); AllChildren++)
			{
				Min = min(Min, (MiniMax(N->GetChild(AllChildren))));
			}
			N->SetValue(Min);
			return Min;
		}

	}

}

