#pragma once

#include <iostream>
#include "Paddle.h"

class UserPaddle : public Paddle {
public:
	UserPaddle() { //origin is top left, so (0,0) is top left
		posX = 0;
		posY = 0;
	}
	UserPaddle(float x, float y) {
		posX = x;
		posY = y;
	}
	~UserPaddle() {
	}
	void PaddleUp() override;
	void PaddleDown() override;
	void Render() override; //do not provide definition {} in .h if definition is shown in .cpp
	
};
