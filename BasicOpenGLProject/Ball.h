#pragma once

#include <iostream>

class Ball {
protected:
	float posX; 
	float posY;
	float vx;
	float vy;
public:
	Ball() { 
		posX = 0;
		posY = 0;
		vx = 0.00005f;
		vy = 0.000015f;
	}
	Ball(float x, float y) {
		posX = x;
		posY = y;
		vx = 0.00005f;
		vy = 0.000015f;
	}
	~Ball() {
	}
	void BallRender();
	void BallMove();
	float getBallX();
	float getBallY();
};