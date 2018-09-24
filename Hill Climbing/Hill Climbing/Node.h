#pragma once

class Node
{
public:

	Node(int InitIndex, float Initx, float Inity);
	~Node();

	int GetIndex();
	float GetxPos();
	float GetyPos();

	void SetIndex(int NewIndex);
	void SetxPos(float NewxPos);
	void SetyPos(float NewyPos);

private: 

	int	  Index;
	float xPos;
	float yPos;
};