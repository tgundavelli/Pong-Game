#pragma once

#include <iostream>
#include "Paddle.h"

class UserPaddle : public Paddle {
protected:
	int posX;
	int posY;
public:
	Paddle() { //origin is top left, so (0,0) is top left
		posX = 0;
		posY = 0;
	}
	Paddle(int x, int y) {
		posX = x;
		posY = y;
	}
	virtual ~Paddle() {
	}
	virtual void PaddleUp() override {};
	virtual void PaddleDown() override {};
};
