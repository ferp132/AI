#pragma once

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

class ColouredObject
{
public:

private: 
	GLuint VBO;	//Vertex Buffer Object
	GLuint VAO;	//Vertex Array Object
	GLuint EBO;	//Element Buffer Object
	GLuint* Vertices; 
	GLuint* Indicies;
};