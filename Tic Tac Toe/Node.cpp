#include "Node.h"

Node::Node(Node* MyParent)							//Constructor if Created By Parent Node
{

	Parent					= MyParent;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			BoardState.SetTile(Parent->GetBoardState()->GetTile(y, x), y, x);
		}
	}
	Depth					= Parent->GetDepth() - 1;
	MinMax					= !Parent->GetMinMax();
	Difficulty = Parent->GetDifficulty();
}

Node::Node(Board RootBoardState, int RootDepth, bool RootDifficulty)	//Constructor when Created as the Root
{
	Parent	   = nullptr;
	BoardState = RootBoardState;
	Depth	   = RootDepth;
	MinMax	   = false;				//Max = true = O
	Difficulty = RootDifficulty;
}

Node::~Node()
{
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
//	if(WhichChild <= Depth) Children. = NewChild;
//	else cout << "Failed To Set Child" << endl;
}

bool Node::GetDifficulty()
{
	return Difficulty;
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

vector<Node*> Node::GetChildren()
{
	return Children;
}

Node * Node::GetChild(int WhichChild)
{
	if (WhichChild <= size(Children)) return Children.at(WhichChild);
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

Board Node::GetBoard()
{
	return BoardState;
}

Node * Node::CreateChild()
{
	Node* NewNode = new Node(this);
	Children.push_back(NewNode);
	return NewNode;
}

void Node::CreateLayer()
{
	for (unsigned int D = 0; D < 9; D++)
	{
			int yLoc = D / 3;
			int xLoc = D % 3;
			if (BoardState.GetTile(yLoc, xLoc) == 0)
			{
				//Create a new child Node
				Node* CurrentChild = CreateChild();
				CurrentChild->GetBoardState()->SetTile(CurrentChild->GetMinMax() + 1, yLoc, xLoc);
				
				if (Difficulty) CurrentChild->SetValue(CurrentChild->CheckStateHard());
				else			CurrentChild->SetValue(CurrentChild->CheckStateEasy());
			}
	}
}

int Node::CheckStateEasy()
{
	int Value;
	//Winning Conditions;
	bool WinHorz1 = (BoardState.GetTile(0, 0) == O) && (BoardState.GetTile(0, 1) == O) && (BoardState.GetTile(0, 2) == O); //First Row
	bool WinHorz2 = (BoardState.GetTile(1, 0) == O) && (BoardState.GetTile(1, 1) == O) && (BoardState.GetTile(1, 2) == O); //Second Row	
	bool WinHorz3 = (BoardState.GetTile(2, 0) == O) && (BoardState.GetTile(2, 1) == O) && (BoardState.GetTile(2, 2) == O); //Third Row
	bool WinVert1 = (BoardState.GetTile(0, 0) == O) && (BoardState.GetTile(1, 0) == O) && (BoardState.GetTile(2, 0) == O); //First Collumn
	bool WinVert2 = (BoardState.GetTile(0, 1) == O) && (BoardState.GetTile(1, 1) == O) && (BoardState.GetTile(2, 1) == O); //Second Collumn
	bool WinVert3 = (BoardState.GetTile(0, 2) == O) && (BoardState.GetTile(1, 2) == O) && (BoardState.GetTile(2, 2) == O); //Third Collumn
	bool WinDiag1 = (BoardState.GetTile(0, 0) == O) && (BoardState.GetTile(1, 1) == O) && (BoardState.GetTile(2, 2) == O); //Diagonal From Top Left
	bool WinDiag2 = (BoardState.GetTile(0, 2) == O) && (BoardState.GetTile(1, 1) == O) && (BoardState.GetTile(2, 0) == X); //Diagonal From Top Right

	bool LoseHorz1 = (BoardState.GetTile(0, 0) == X) && (BoardState.GetTile(0, 1) == X) && (BoardState.GetTile(0, 2) == X); //First Row
	bool LoseHorz2 = (BoardState.GetTile(1, 0) == X) && (BoardState.GetTile(1, 1) == X) && (BoardState.GetTile(1, 2) == X); //Second Row	
	bool LoseHorz3 = (BoardState.GetTile(2, 0) == X) && (BoardState.GetTile(2, 1) == X) && (BoardState.GetTile(2, 2) == X); //Third Row
	bool LoseVert1 = (BoardState.GetTile(0, 0) == X) && (BoardState.GetTile(1, 0) == X) && (BoardState.GetTile(2, 0) == X); //First Collumn
	bool LoseVert2 = (BoardState.GetTile(0, 1) == X) && (BoardState.GetTile(1, 1) == X) && (BoardState.GetTile(2, 1) == X); //Second Collumn
	bool LoseVert3 = (BoardState.GetTile(0, 2) == X) && (BoardState.GetTile(1, 2) == X) && (BoardState.GetTile(2, 2) == X); //Third Collumn
	bool LoseDiag1 = (BoardState.GetTile(0, 0) == X) && (BoardState.GetTile(1, 1) == X) && (BoardState.GetTile(2, 2) == X); //Diagonal From Top Left
	bool LoseDiag2 = (BoardState.GetTile(0, 2) == X) && (BoardState.GetTile(1, 1) == X) && (BoardState.GetTile(2, 0) == X); //Diagonal From Top Right

	if (WinHorz1 || WinHorz2 || WinHorz3 || WinVert1 || WinVert2 || WinVert3 || WinDiag1 || WinDiag2)
	{
		return 1;
	}
	else if (LoseHorz1 || LoseHorz2 || LoseHorz3 || LoseVert1 || LoseVert2 || LoseVert3 || LoseDiag1 || LoseDiag2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int Node::CheckStateHard()
{
	int Value = 0;	
	array<int, 3> HorzLine1{ { BoardState.GetTile(0, 0), BoardState.GetTile(0, 1), BoardState.GetTile(1, 2) } };
	array<int, 3> HorzLine2{ { BoardState.GetTile(1, 0), BoardState.GetTile(1, 1), BoardState.GetTile(0, 2) } };
	array<int, 3> HorzLine3{ { BoardState.GetTile(2, 0), BoardState.GetTile(2, 1), BoardState.GetTile(2, 2) } };
	array<int, 3> VertLine1{ { BoardState.GetTile(0, 0), BoardState.GetTile(1, 0), BoardState.GetTile(2, 0) } };
	array<int, 3> VertLine2{ { BoardState.GetTile(0, 1), BoardState.GetTile(1, 1), BoardState.GetTile(2, 1) } };
	array<int, 3> VertLine3{ { BoardState.GetTile(0, 2), BoardState.GetTile(1, 2), BoardState.GetTile(2, 2) } };
	array<int, 3> DiagLine1{ { BoardState.GetTile(0, 0), BoardState.GetTile(1, 1), BoardState.GetTile(2, 2) } };
	array<int, 3> DiagLine2{ { BoardState.GetTile(0, 2), BoardState.GetTile(1, 1), BoardState.GetTile(2, 0) } };

	array<int, 3> Win{ { O, O, O } };
	array<int, 3> Loss{ { X, X, X } };
	array<int, 3> PosTwo1{ { O, 0, O } };
	array<int, 3> PosTwo2{ { 0, O, O } };
	array<int, 3> PosTwo3{ { O, O, 0 } };
	array<int, 3> NegTwo1{ { X, 0, X } };
	array<int, 3> NegTwo2{ { 0, X, X } };
	array<int, 3> NegTwo3{ { X, X, 0 } };
	array<int, 3> PosOne1{ { 0, 0, O } };
	array<int, 3> PosOne2{ { O, 0, 0 } };
	array<int, 3> PosOne3{ { 0, O, 0 } };
	array<int, 3> NegOne1{ { 0, 0, X } };
	array<int, 3> NegOne2{ { X, 0, 0 } };
	array<int, 3> NegOne3{ { 0, X, 0 } };

	if		(HorzLine1 == Win) Value += 100;
	else if (HorzLine1 == Loss) Value -= 100;
	else if (HorzLine1 == PosTwo1) Value += 10;
	else if (HorzLine1 == PosTwo2) Value += 10;
	else if (HorzLine1 == PosTwo3) Value += 10;
	else if (HorzLine1 == NegTwo1) Value -= 10;
	else if (HorzLine1 == NegTwo2) Value -= 10;
	else if (HorzLine1 == NegTwo3) Value -= 10;
	else if (HorzLine1 == PosOne1) Value += 1;
	else if (HorzLine1 == PosOne2) Value += 1;
	else if (HorzLine1 == PosOne3) Value += 1;
	else if (HorzLine1 == NegOne1) Value -= 1;
	else if (HorzLine1 == NegOne2) Value -= 1;
	else if (HorzLine1 == NegOne3) Value -= 1;

	if (HorzLine2 == Win) Value += 100;
	else if (HorzLine2 == Loss) Value -= 100;
	else if (HorzLine2 == PosTwo1) Value += 10;
	else if (HorzLine2 == PosTwo2) Value += 10;
	else if (HorzLine2 == PosTwo3) Value += 10;
	else if (HorzLine2 == NegTwo1) Value -= 10;
	else if (HorzLine2 == NegTwo2) Value -= 10;
	else if (HorzLine2 == NegTwo3) Value -= 10;
	else if (HorzLine2 == PosOne1) Value += 1;
	else if (HorzLine2 == PosOne2) Value += 1;
	else if (HorzLine2 == PosOne3) Value += 1;
	else if (HorzLine2 == NegOne1) Value -= 1;
	else if (HorzLine2 == NegOne2) Value -= 1;
	else if (HorzLine2 == NegOne3) Value -= 1;

	if (HorzLine3 == Win) Value += 100;
	else if (HorzLine3 == Loss) Value -= 100;
	else if (HorzLine3 == PosTwo1) Value += 10;
	else if (HorzLine3 == PosTwo2) Value += 10;
	else if (HorzLine3 == PosTwo3) Value += 10;
	else if (HorzLine3 == NegTwo1) Value -= 10;
	else if (HorzLine3 == NegTwo2) Value -= 10;
	else if (HorzLine3 == NegTwo3) Value -= 10;
	else if (HorzLine3 == PosOne1) Value += 1;
	else if (HorzLine3 == PosOne2) Value += 1;
	else if (HorzLine3 == PosOne3) Value += 1;
	else if (HorzLine3 == NegOne1) Value -= 1;
	else if (HorzLine3 == NegOne2) Value -= 1;
	else if (HorzLine3 == NegOne3) Value -= 1;

	if (VertLine1 == Win) Value += 100;
	else if (VertLine1 == Loss) Value -= 100;
	else if (VertLine1 == PosTwo1) Value += 10;
	else if (VertLine1 == PosTwo2) Value += 10;
	else if (VertLine1 == PosTwo3) Value += 10;
	else if (VertLine1 == NegTwo1) Value -= 10;
	else if (VertLine1 == NegTwo2) Value -= 10;
	else if (VertLine1 == NegTwo3) Value -= 10;
	else if (VertLine1 == PosOne1) Value += 1;
	else if (VertLine1 == PosOne2) Value += 1;
	else if (VertLine1 == PosOne3) Value += 1;
	else if (VertLine1 == NegOne1) Value -= 1;
	else if (VertLine1 == NegOne2) Value -= 1;
	else if (VertLine1 == NegOne3) Value -= 1;

	if (VertLine2 == Win) Value += 100;
	else if (VertLine2 == Loss) Value -= 100;
	else if (VertLine2 == PosTwo1) Value += 10;
	else if (VertLine2 == PosTwo2) Value += 10;
	else if (VertLine2 == PosTwo3) Value += 10;
	else if (VertLine2 == NegTwo1) Value -= 10;
	else if (VertLine2 == NegTwo2) Value -= 10;
	else if (VertLine2 == NegTwo3) Value -= 10;
	else if (VertLine2 == PosOne1) Value += 1;
	else if (VertLine2 == PosOne2) Value += 1;
	else if (VertLine2 == PosOne3) Value += 1;
	else if (VertLine2 == NegOne1) Value -= 1;
	else if (VertLine2 == NegOne2) Value -= 1;
	else if (VertLine2 == NegOne3) Value -= 1;

	if (VertLine3 == Win) Value += 100;
	else if (VertLine3 == Loss) Value -= 100;
	else if (VertLine3 == PosTwo1) Value += 10;
	else if (VertLine3 == PosTwo2) Value += 10;
	else if (VertLine3 == PosTwo3) Value += 10;
	else if (VertLine3 == NegTwo1) Value -= 10;
	else if (VertLine3 == NegTwo2) Value -= 10;
	else if (VertLine3 == NegTwo3) Value -= 10;
	else if (VertLine3 == PosOne1) Value += 1;
	else if (VertLine3 == PosOne2) Value += 1;
	else if (VertLine3 == PosOne3) Value += 1;
	else if (VertLine3 == NegOne1) Value -= 1;
	else if (VertLine3 == NegOne2) Value -= 1;
	else if (VertLine3 == NegOne3) Value -= 1;

	if (DiagLine1 == Win) Value += 100;
	else if (DiagLine1 == Loss) Value -= 100;
	else if (DiagLine1 == PosTwo1) Value += 10;
	else if (DiagLine1 == PosTwo2) Value += 10;
	else if (DiagLine1 == PosTwo3) Value += 10;
	else if (DiagLine1 == NegTwo1) Value -= 10;
	else if (DiagLine1 == NegTwo2) Value -= 10;
	else if (DiagLine1 == NegTwo3) Value -= 10;
	else if (DiagLine1 == PosOne1) Value += 1;
	else if (DiagLine1 == PosOne2) Value += 1;
	else if (DiagLine1 == PosOne3) Value += 1;
	else if (DiagLine1 == NegOne1) Value -= 1;
	else if (DiagLine1 == NegOne2) Value -= 1;
	else if (DiagLine1 == NegOne3) Value -= 1;

	if (DiagLine2 == Win) Value += 100;
	else if (DiagLine2 == Loss) Value -= 100;
	else if (DiagLine2 == PosTwo1) Value += 10;
	else if (DiagLine2 == PosTwo2) Value += 10;
	else if (DiagLine2 == PosTwo3) Value += 10;
	else if (DiagLine2 == NegTwo1) Value -= 10;
	else if (DiagLine2 == NegTwo2) Value -= 10;
	else if (DiagLine2 == NegTwo3) Value -= 10;
	else if (DiagLine2 == PosOne1) Value += 1;
	else if (DiagLine2 == PosOne2) Value += 1;
	else if (DiagLine2 == PosOne3) Value += 1;
	else if (DiagLine2 == NegOne1) Value -= 1;
	else if (DiagLine2 == NegOne2) Value -= 1;
	else if (DiagLine2 == NegOne3) Value -= 1;

	return Value;
}
