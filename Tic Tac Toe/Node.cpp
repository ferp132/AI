#include "Node.h"

Node::Node(Node* MyParent)							//Constructor if Created By Parent Node
{
	Parent					= MyParent;
	BoardState				= Parent->BoardState;
	Depth					= Parent->GetDepth() - 1;
	MinMax					= !Parent->GetMinMax();
	if(Depth > 0) Children  = new Node*[Depth];
	else		  Children  = nullptr;

	//Set its value to 1 if THe AI Wins, -1 if it loses
	if		(BoardState.CheckWin(2)) Value = 1;		// 2 = O = AI Symbol
	else if (BoardState.CheckWin(1)) Value = -1;	// 1 = X = Player
}

Node::Node(Board RootBoardState, int RootDepth)	//Constructor when Created as the Root
{
	Parent	   = nullptr;
	BoardState = RootBoardState;
	Depth	   = RootDepth;
	MinMax	   = true;
	Children   = new Node*[Depth];

}

Node::~Node()
{
	for (int i = 0; i < Depth; i++)
	{
		delete Children[i];
	}
}

void Node::SetMinMax(bool NewMinMax)
{
	MinMax = NewMinMax;
}

void Node::SetDepth(int NewDepth)
{
	Depth = NewDepth;
}

void Node::SetValue(int NewValue)
{
	Value = NewValue;
}

void Node::SetAlpha(int NewAlpha)
{
	Alpha = NewAlpha;
}

void Node::SetBeta(int NewBeta)
{
	Beta = NewBeta;
}

void Node::SetParent(Node * NewParent)
{
	Parent = NewParent;
}

void Node::SetChild(Node * NewChild, unsigned int WhichChild)
{
	if(WhichChild <= Depth) Children[Depth] = NewChild;
	else cout << "Failed To Set Child" << endl;
}

bool Node::GetMinMax()
{
	return MinMax;
}

int Node::GetDepth()
{
	return Depth;
}

int Node::GetValue()
{
	return Value;
}

int Node::GetAlpha()
{
	return Alpha;
}

int Node::GetBeta()
{
	return Beta;
}

Node * Node::GetParent()
{
	return Parent;
}

Node * Node::GetChild(unsigned int WhichChild)
{
	if (WhichChild <= Depth) return Children[WhichChild];
	else
	{
		cout << "Failed to Get Child" << endl;
		return nullptr;
	}
}

Board * Node::GetBoardState()
{
	return &BoardState;
}

Node * Node::CreateChild(unsigned int ChildNumber)
{
	Children[ChildNumber] = new Node(BoardState, Depth);
	return Children[ChildNumber];
}
