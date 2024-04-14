#pragma once

#include <iostream>
#include "Paddle.h"

class UserPaddle : public Paddle {
protected:
	float posX;
	float posY;
public:
	UserPaddle() { //origin is top left, so (0,0) is top left
		posX = 0;
		posY = 0;
	}
	UserPaddle(float x, float y) {
		posX = x;
		posY = y;
	}
	virtual ~UserPaddle() {
	}
	virtual void PaddleUp() override;
	virtual void PaddleDown() override;
	virtual void Render() override; //do not provide definition {} in .h if definition is shown in .cpp
};
