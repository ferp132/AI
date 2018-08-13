#include "Window.h"

Window::Window(int initWidth, int initHeight, int initxPos, int inityPos, int initMode, const char* initName)
{
	Width		= initWidth;
	Height		= initHeight;
	xPos		= initxPos;
	yPos		= inityPos;
	DisplayMode = initMode;
	WindowName	= initName;

	Initialise();
}

Window::~Window()
{
}

void Window::Initialise()
{
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(xPos, yPos);
	glutInitWindowSize(Width, Height);
	glutCreateWindow(WindowName);
}

void Window::SetWidth(int newWidth)
{
	Width = newWidth;
	return;
}

void Window::SetHeight(int newHeight)
{
	Height = newHeight;
	return;
}

int Window::GetWidth()
{
	return Width;
}

int Window::GetHeight()
{
	return Height;
}

void Window::SetxPos(int newxPos)
{
	xPos = newxPos;
	return;
}

void Window::SetyPos(int newyPos)
{
	yPos = newyPos;
	return;
}

int Window::GetxPos()
{
	return xPos;
}

int Window::GetyPos()
{
	return yPos;
}

//void Window::SetMode(int newMode)
//{
//	DisplayMode = newMode;
//	return;
//}
//
//unsigned int Window::GetMode()
//{
//	return DisplayMode;
//}

void Window::SetName(const char* newName)
{
	WindowName = newName;
	return;
}

const char* Window::GetName()
{
	return WindowName;
}
