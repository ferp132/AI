#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>

class Window 
{
public:
	Window(int initWidth, int initHeight, int initxPos, int inityPos, int initMode, const char* initName);
	~Window();

	void Initialise();

	void SetWidth (int newWidth);
	void SetHeight(int newHeight);
	int  GetWidth ();
	int  GetHeight();

	void SetxPos(int newxPos);
	void SetyPos(int newyPos);
	int  GetxPos();
	int  GetyPos();

//	void SetMode(int newMode);		These are currently redundant because I need to set up functionality for bitwise or 
//	int	 GetMode();

	void		SetName(const char* newName);
	const char* GetName();

private:
	int Width, Height;
	int xPos, yPos;
	int DisplayMode;
	const char* WindowName;
};