#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

	//	cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				rotationAngleX += 1.0f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				rotationAngleX -= 1.0f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				rotationAngleY += 1.0f;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rotationAngleY -= 1.0f;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				dy -= 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				dy += 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				dx -= 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				dx += 1;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				scaleFactorX += 10.0;
				scaleFactorY += 10.0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				scaleFactorX -= 10.0;
				scaleFactorY -= 10.0;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	//glBegin(GL_QUADS);
	//{
	//	rotation = rotation.Rotation(rotationAngle);
	//	scale = scale.Scale(scaleFactorX, scaleFactorY);
	//	translation = translation.Translate(dx, dy);
	//	
	//	std::cout << scale.A11 << std::endl;
	//	std::cout << scale.A12 << std::endl;
	//	//Back Face
	//	glColor3f(0.0f, 1.0f, 0.0f);

	//	vertexPosition = Vector3D(1.0f, 1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, 1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, -1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	////	vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, -1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);



	//	glColor3f(1.0f, 1.0f, 0.0f);

	//	vertexPosition = Vector3D(-1.0f, 1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, 1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, -1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, -1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);



	//	glColor3f(1.0f, 1.0f, 1.0f);

	//	vertexPosition = Vector3D(1.0f, 1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, 1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, -1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, -1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);



	//	glColor3f(0.0f, 1.0f, 1.0f);

	//	vertexPosition = Vector3D(-1.0f, -1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, -1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, -1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, -1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);



	//	glColor3f(0.0f, 2.0f, 1.0f);

	//	vertexPosition = Vector3D(1.0f, 1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, 1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, 1.0f, -15.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, 1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);


	//	//Front Face
	//	glColor3f(0.0f, 0.0f, 1.0f);

	//	vertexPosition = Vector3D(1.0f, 1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, 1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(-1.0f, -1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

	//	vertexPosition = Vector3D(1.0f, -1.0f, -5.0f);
	//	//vertexPosition = rotation * vertexPosition;
	//	vertexPosition = scale * vertexPosition;
	//	//vertexPosition = translation * vertexPosition;

	//	glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);
	//	//Complete the faces of the Cube
	//}
	//glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 0.1f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.05f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	//cout << "Update up" << endl;
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();

	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	//glRotated(rotationAngle, 0, 1, 0);
	glTranslatef(0, 0, -10);
	glBegin(GL_QUADS);
	{
		rotationX = rotationX.RotationX(rotationAngleX);
		rotationY = rotationY.RotationY(rotationAngleY);

		scale = scale.Scale(scaleFactorX,scaleFactorY);


		translation = translation.Translate(dx, dy);

		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);

		vertexPosition = Vector3D(1.0f, 1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, 1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, -1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, -1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);


		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);

		vertexPosition = Vector3D(1.0f, 1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, 1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, -1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, -1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);



		//Side face 1

		glColor3f(1.0f, 1.0f, 0.0f);

		vertexPosition = Vector3D(-1.0f, 1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, 1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, -1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, -1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);


		//Side face 2
		glColor3f(1.0f, 1.0f, 1.0f);

		vertexPosition = Vector3D(1.0f, 1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, 1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, -1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, -1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);


		//Side face 3
		glColor3f(0.0f, 1.0f, 1.0f);

		vertexPosition = Vector3D(-1.0f, -1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, -1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, -1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, -1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);


		//Side face 4
		glColor3f(0.0f, 2.0f, 1.0f);

		vertexPosition = Vector3D(1.0f, 1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(1.0f, 1.0f, -15.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY* vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, 1.0f, -15.0f);
		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		vertexPosition = Vector3D(-1.0f, 1.0f, -5.0f);

		vertexPosition = rotationX * vertexPosition;
		vertexPosition = rotationY * vertexPosition;

		vertexPosition = scale * vertexPosition;
		vertexPosition = translation * vertexPosition;

		glVertex3f(vertexPosition.x, vertexPosition.y, vertexPosition.z);

		//Complete the faces of the Cube
	}
	glEnd();
	glCallList(1);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

