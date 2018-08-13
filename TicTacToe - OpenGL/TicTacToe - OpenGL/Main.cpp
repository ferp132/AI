//-----OpenGL Dependencies
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

//-----My Files
#include "Window.h"

#include <iostream>

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0);

	glutSwapBuffers();
}

int main(int argc, char ** argv) 
{
	glutInit(&argc, argv);
	Window MainWindow(800, 600, 100, 100, GLUT_DEPTH, "Does This Work?");

	glClearColor(1.0, 0.0, 0.0, 1.0); //Clear Red

	//register callbacks
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
}