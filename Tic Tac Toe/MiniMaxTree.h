#pragma once
#include <algorithm>

#include "Node.h"

using namespace std;
class MiniMaxTree
{
public:
	MiniMaxTree();
	~MiniMaxTree();

	Board InitMiniMax(Board InitBoardState, unsigned int InitDepth, bool InitDifficulty);
	int MiniMax(Node* N);

private:
	Node * CurrentRoot;
	Node * MaxNode;
};