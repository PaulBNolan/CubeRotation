#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	Clock clock;
	Time elapsed;


	Matrix3 rotationX;
	Matrix3 rotationY;
	Matrix3 translation;
	Matrix3 scale;

	double scaleFactor = 100;

	int dx = 0;
	int dy = 0;

	Vector3D vertexPosition;
	float rotationAngle = 0.0f;

	float rotationAngleX = 0.0f;
	float rotationAngleY = 0.0f;
};