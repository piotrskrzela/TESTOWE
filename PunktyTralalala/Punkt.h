#include <GL\glew.h>
#include <GL\freeglut.h>

#pragma once


GLuint VAO;
GLuint VBO;

class Punkt
{
public:
	Punkt();

	Punkt(int screenWidth, int screenHeigth, int posX, int posY);

	~Punkt();

	void CreateWindowGlut(int argc, char** argv);

	static void Display();

	void CreateVBO();

	void CreateVAO();

	void GlewInitializet();

private:
	int screenWidth;
	int screenHeight;
	int posX;
	int posY;
};

