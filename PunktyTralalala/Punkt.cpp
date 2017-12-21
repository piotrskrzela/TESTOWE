#include "Punkt.h"
#include <iostream>



Punkt::Punkt()
{
	this->screenWidth = 1024;
	this->screenHeight = 768;
	this->posX = 100;
	this->posY = 100;
}

Punkt::Punkt(int screenWidth, int screenHeigth, int posX, int posY)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeigth;
	this->posX = posX;
	this->posY = posY;
}


Punkt::~Punkt()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Punkt::CreateWindowGlut(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(posX, posY);
	glutCreateWindow("punkt");
}

void Punkt::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_VERTEX_ARRAY, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glColor3f(0.0f, 1.0f, 0.0f);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void Punkt::CreateVBO()
{
	GLfloat vertexCoords[9]
	{
		0.0f,0.5f,0.0f,
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f
	};

	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	std::cout<< "VBO: " << VBO << std::endl;

	std::cout << sizeof(vertexCoords) << std::endl;

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCoords), vertexCoords, GL_STATIC_DRAW);

}

void Punkt::CreateVAO()
{
	glGenVertexArrays(1, &VAO);
	std::cout<<"VAO: " << VAO << std::endl;
	glBindVertexArray(VAO);
}

void Punkt::GlewInitializet()
{
	GLenum glewInitializetEnum = glewInit();
	if (glewInitializetEnum != GLEW_OK)
	{
		std::cerr << "cannot initializet glew" << std::endl;
		return;
	}
}

int main(int argc, char ** argv)
{
	Punkt punkt(786, 1024, 100, 100);

	punkt.CreateWindowGlut(argc, argv);
	punkt.GlewInitializet();
	punkt.CreateVAO();
	punkt.CreateVBO();
	glutDisplayFunc(punkt.Display);
	// po zamknieciu okna kontrola wraca do programu
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}