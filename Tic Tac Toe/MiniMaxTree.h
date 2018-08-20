#pragma once
#include "Node.h"

class MiniMaxTree
{
public:
	void InitTree(Board InitBoardState, unsigned int InitDepth);
private:
	Node* CurrentRoot;

};