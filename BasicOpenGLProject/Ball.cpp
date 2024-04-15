#include "Ball.h"
#include <GL/freeglut.h>

void Ball::BallRender(){
	glPushMatrix(); 
	glTranslatef(posX, posY, 0.0f); //Need the matrix gl commands to change position
	glColor3f(1.0f, 0.0f, 1.0f); //set the color to purple
	glutSolidSphere(0.05f, 100.0f, 100.0f); //0.05 for small radius, 100 to make shape rounder
	glPopMatrix();
};

void Ball::BallMove(){
	posX += vx;
	posY += vy;
	if (posX <= -1.0) {
		posX = -1.0;
		vx *= -1;
	}
	if (posX >= 1.0) {
		posX = 1.0;
		vx *= -1;
	}
	if (posY <= -1.0) {
		posY = -1.0;
		vy *= -1;
		std::cout << posX << posY;
	}
	if (posY >= 1.0) {
		posY = 1.0;
		vy *= -1;
		std::cout << posX << posY;
	}
};

float Ball::getBallX() {
	return posX;
};

float Ball::getBallY() {
	return posY;
}