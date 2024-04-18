#include "Ball.h"
#include "Game.h"
#include <GL/freeglut.h>

void Ball::BallRender(){
	glPushMatrix(); 
	glTranslatef(posX, posY, 0.0f); //Need the matrix gl commands to change position
	glColor3f(1.0f, 0.0f, 1.0f); //set the color to purple
	glutSolidSphere(0.05f, 100.0f, 100.0f); //0.05 for small radius, 100 to make shape rounder
	glPopMatrix();
};

void Ball::BallMove(bool collide1, bool collide2){
	posX += vx;
	posY += vy;
	//std::cout << posX << " " << posY << " " << vx << " " << vy << "][";
	if (posX <= -1.0) {
		posX = -1.0;
		vx *= -1;
		test->set_OPO(true);
		test->set_OPU(false);
		test->CalculateScore();
		test->reset_bools();
	}
	if (posX >= 1.0) {
		posX = 1.0;
		vx *= -1;
		test->set_OPO(false);
		test->set_OPU(true);
		test->CalculateScore();
		test->reset_bools();
	}
	if (posY <= -1.0) {
		posY = -1.0;
		vy *= -1;
	}
	if (posY >= 1.0) {
		posY = 1.0;
		vy *= -1;

	}
	if (collide1) {
		posX += 0.05;
	    vx *= -1;
		test->set_UP(true);
		test->set_OP(false);
	}
	if (collide2) {
		posX -= 0.05;
		vx *= -1;
		test->set_UP(false);
		test->set_OP(true);
	}
};

float Ball::getBallX() {
	return posX;
};

float Ball::getBallY() {
	return posY;
}