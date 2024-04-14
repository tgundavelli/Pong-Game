#pragma once

#include <iostream>

class Paddle {
protected:
	float posX; //float for glRectf
	float posY;
public :
	Paddle() { //origin is top left, so (0,0) is top left
		posX = 0;
		posY = 0;
	}
	Paddle(float x, float y) {
		posX = x;
		posY = y;
	}
	virtual ~Paddle() {
	}
	virtual void PaddleUp() = 0;
	virtual void PaddleDown() = 0;
	virtual void Render() = 0;
};



//make a paddle 