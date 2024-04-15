#include "OtherPaddle.h"
#include <GL/freeglut.h>

void OtherPaddle::Render() {
	glColor3f(0.5f, 0.5f, 0.5f); //set the color
	glRectf(posX, posY, posX + 0.1f, posY + 0.4f); //create the rectangle based on coordinates
};

void OtherPaddle::PaddleUp(float Ball_posX, float Ball_posY) {
	if (Ball_posY > (posY + 0.2f)) {
		posY += 0.00005f;
	}
	glutPostRedisplay();
};

void OtherPaddle::PaddleDown(float Ball_posX, float Ball_posY) {
	if (Ball_posY < (posY + 0.2f)) {
		posY -= 0.000015f;
	}
	glutPostRedisplay();
};
