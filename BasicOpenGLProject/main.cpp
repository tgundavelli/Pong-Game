#include <GL/freeglut.h>
#include <iostream>
#include "UserPaddle.h"
#include "OtherPaddle.h"
#include "Ball.h"
#include "Game.h"

//=================================================================================================
// CALLBACKS
//=================================================================================================

//-----------------------------------------------------------------------------
// CALLBACK DOCUMENTATION
// https://www.opengl.org/resources/libraries/glut/spec3/node45.html
// http://freeglut.sourceforge.net/docs/api.php#WindowCallback
//-----------------------------------------------------------------------------

UserPaddle paddle1(-0.97f,-0.25f); //Include UserPaddle.h not UserPaddle.cpp
OtherPaddle paddle2(0.87f,-0.25f); //position is middle right
Ball the_ball(0,0);
Game hit;

void idle_func()
{
	//uncomment below to repeatedly draw new frames
	the_ball.BallMove(hit.Collision(the_ball.getBallX(), the_ball.getBallY(), paddle1.getPaddleX(), paddle1.getPaddleY()), hit.Collision(the_ball.getBallX(), the_ball.getBallY(), paddle2.getPaddleX(), paddle2.getPaddleY()));
	paddle2.PaddleUp(the_ball.getBallX(), the_ball.getBallY());
	paddle2.PaddleDown(the_ball.getBallX(), the_ball.getBallY());
	glutPostRedisplay();
}

void reshape_func(int width, int height)
{
	glViewport(0, 0, width, height);
	glutPostRedisplay();
}

void keyboard_func(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': //I don't know how to do Arrow key
	{
		paddle1.PaddleUp();
		break;
	}

	case 's':
	{
		paddle1.PaddleDown();
		break;
	}

	case 'a':
	{
		break;
	}

	case 'd':
	{
		break;
	}

	// Exit on escape key press
	case '\x1B':
	{
		exit(EXIT_SUCCESS);
		break;
	}
	}

	glutPostRedisplay();
}

void key_released(unsigned char key, int x, int y)
{
}

void key_special_pressed(int key, int x, int y)
{
}

void key_special_released(int key, int x, int y)
{
}

void mouse_func(int button, int state, int x, int y)
{
}

void passive_motion_func(int x, int y)
{
}

void active_motion_func(int x, int y)
{
}

//=================================================================================================
// RENDERING
//=================================================================================================

void display_func(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	paddle1.Render();
	paddle2.Render();
	the_ball.BallRender();
	glutSwapBuffers();
}

//=================================================================================================
// INIT
//=================================================================================================

void init(void)
{
	// Print some info
	//std::cout << "Vendor:         " << glGetString(GL_VENDOR) << "\n";
	//std::cout << "Renderer:       " << glGetString(GL_RENDERER) << "\n";
	//std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n\n";

	// Set the background color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	std::cout << "Finished initializing...\n\n";
}

//=================================================================================================
// MAIN
//=================================================================================================

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutCreateWindow("Pong Game");

	glutDisplayFunc(display_func);
	glutIdleFunc(idle_func);
	glutReshapeFunc(reshape_func);
	glutKeyboardFunc(keyboard_func);
	glutKeyboardUpFunc(key_released);
	glutSpecialFunc(key_special_pressed);
	glutSpecialUpFunc(key_special_released);
	glutMouseFunc(mouse_func);
	glutMotionFunc(active_motion_func);
	glutPassiveMotionFunc(passive_motion_func);

	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}
