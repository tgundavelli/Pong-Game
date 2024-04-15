#pragma once

#include <iostream>
#include "Paddle.h"

class OtherPaddle : public Paddle {
protected:
	float posX;
	float posY;
public:
	OtherPaddle() { //origin is top left, so (0,0) is top left
		posX = 0;
		posY = 0;
	}
	OtherPaddle(float x, float y) {
		posX = x;
		posY = y;
	}
	virtual ~OtherPaddle() {
	}
	void PaddleUp() override {}; //needed to instantiate abstract class
	void PaddleDown() override {};
	void PaddleUp(float Ball_posX, float Ball_posY); //no override because different parameters
	void PaddleDown(float Ball_posX, float Ball_posY);
	virtual void Render() override; //do not provide definition {} in .h if definition is shown in .cpp
};
