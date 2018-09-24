#include "Node.h"

Node::Node(int InitIndex, float Initx, float Inity)
{
	Index = InitIndex;
	xPos = Initx;
	yPos = Inity;
}

Node::~Node()
{
}

int Node::GetIndex()
{
	return Index;
}

float Node::GetxPos()
{
	return xPos;
}

float Node::GetyPos()
{
	return yPos;
}

void Node::SetIndex(int NewIndex)
{
	Index = NewIndex;
}

void Node::SetxPos(float NewxPos)
{
	xPos = NewxPos;
}

void Node::SetyPos(float NewyPos)
{
	yPos = NewyPos;
}
