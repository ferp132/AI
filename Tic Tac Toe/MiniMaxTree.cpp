#include "MiniMaxTree.h"

void MiniMaxTree::InitTree(Board InitBoardState, unsigned int InitDepth)
{
	CurrentRoot = new Node(InitBoardState, InitDepth);
	
	for (unsigned int D1 = 0; D1 < InitDepth; D1++)
	{
		Node* CurrentChild = CurrentRoot->CreateChild(D1);

		//Where to Try and Put a Symbol
		int ToCheck = CurrentChild->GetDepth();
		while (true)
		{
			int xLoc = ToCheck / 3;
			int yLoc = ToCheck % 3;
			if (CurrentChild->GetBoardState()->GetTile(yLoc, xLoc) == 0)	//if This tile is already taken, try the next one, unless its the last one
			{
				CurrentChild->GetBoardState()->SetTile(CurrentChild->GetMinMax() + 1, xLoc, yLoc);
				break;
			}
			else if (ToCheck >= 8) ToCheck = 0;
			else ToCheck++;
		}
	}
}
