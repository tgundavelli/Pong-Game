#include "OtherPaddle.h"
#include <GL/freeglut.h>
#include <cstdlib>

void OtherPaddle::Render() {
	glColor3f(0.5f, 0.5f, 0.5f); //set the color
	glRectf(posX, posY, posX + 0.04f, posY + 0.3f); //create the rectangle based on coordinates
};

void OtherPaddle::PaddleUp(float Ball_posX, float Ball_posY) {
	if (Ball_posY > (posY + 0.2f)) {
		if (rand() % 100 <= 30) {
			posY -= 0.0007f;
		}
		else {
			posY += 0.0007f;
		}
	}
	glutPostRedisplay();
};

void OtherPaddle::PaddleDown(float Ball_posX, float Ball_posY) {
	if (Ball_posY < (posY + 0.2f)) {
		if (rand() % 100 <= 30) {
			posY += 0.0007f;
		}
		else {
			posY -= 0.0007f;
		}
	}
	glutPostRedisplay();
};
