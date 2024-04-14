#include "UserPaddle.h"
#include <GL/freeglut.h>

void UserPaddle::Render(){
	glColor3f(1.0f, 1.0f, 1.0f); //set the color
	glRectf(posX, posY, posX + 0.1f, posY + 0.4f); //create the rectangle based on coordinates
};

void UserPaddle::PaddleUp() {
	posY += 0.1f;
	glutPostRedisplay();
}

void UserPaddle::PaddleDown() {
	posY -= 0.1f;
	glutPostRedisplay();
}
