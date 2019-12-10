#include <Game.h>

// // Uncomment for Part 2
// // ********************
bool flip = false;
int current = 1;
// // ********************

 // Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(11)
{
	// // Uncomment for Part 2
	// // ********************
	 index = glGenLists(primatives);
	// // ********************
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
			{
				glScalef(1.01f, 1.01f, 1.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				glScalef(0.99f, 0.99f, 1.0f);
			}

			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	// // Uncomment for Part 2
	// // ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glPointSize(2.0f);
	glBegin(GL_POINTS);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();
		
	
	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();
		

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();
		
	
	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();
		
	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.0, 2.0, 5.0);
		glVertex3f(2.0, -2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(-2.0, 0.0, -5.0);
	}
	glEnd();
	glEndList();
		
	
	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
		glVertex3f(-0.0, 2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
		glVertex3f(2.0, 2.0, -5.0);
	}
	glEnd();
	glEndList();
		
	
	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glVertex3f(-2.0, 0.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, 0.0, -5.0);
		glVertex3f(2.0, 2.0, -5.0);
	}
	glEnd();
	glEndList();
		
	
	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(-2.0, 0.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
		glVertex3f(2.0, 0.0, -5.0);
	}
	glEnd();
	glEndList();
		
	
	glNewList(index + 10, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glVertex3f(-2.0, 0.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
		glVertex3f(-2.0, -0.0, 5.0);
	}
	glEnd();
	glEndList();

	// // Uncomment for Part 2
	// // ********************
}

void Game::update()
{

	// // Uncomment for Part 2
	// // ********************
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
	{
		glRotatef(-0.2f, 0.0f, 0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
	{
		glRotatef(0.2f, 0.0f, 0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		glTranslatef(-0.01f, 0.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		glTranslatef(0.01f, 0.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		glTranslatef(0.0f, 0.01f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		glTranslatef(0.0f, -0.01f, 0.0f);
	}

	// resets all transformations of shape
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		glLoadIdentity();
	}
	

	// // ********************
	
	cout << "Update up" << endl;
}

void Game::draw()
{

	// // Uncomment for Part 2
	// // ********************
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////Investigate Here!!!!!

	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	// // Uncomment for Part 2
	// // ********************

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

