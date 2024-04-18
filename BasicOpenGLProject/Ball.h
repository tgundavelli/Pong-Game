#pragma once

#include <iostream>
#include "Game.h"

class Ball {
protected:
	float posX; 
	float posY;
	float vx;
	float vy;
	Game* test;
public:
	Ball() { 
		posX = 0;
		posY = 0;
		vx = 0.0007f;
		vy = 0.0002f;
	}
	Ball(float x, float y) {
		posX = x;
		posY = y;
		vx = 0.0007f;
		vy = 0.0002f;
	}
	~Ball() {
	}
	void bidirectional(Game* ptr) {
		test = ptr;
	}
	void BallRender();
	void BallMove(bool collide1, bool collide2);
	float getBallX();
	float getBallY();
};