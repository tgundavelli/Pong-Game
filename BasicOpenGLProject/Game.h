#pragma once

#include <iostream>
#include "Paddle.h"
#include "Ball.h"

class Game {
public:
	bool Collision(float Ball_posX, float Ball_posY, float Paddle_posX, float Paddle_posY) {
		//instead of calculating distances by vertices, find side the center of circle is closest to 
		//rx, ry + 0.4f           rx+0.1f, ry + 0.4f
		//rx, ry                  rx+0.1f, ry
		//left side is rx, top side is ry + 0.4f, right side is rx + 0.1f, bottom side is ry
		float distance1 = abs(Ball_posX - Paddle_posX);
		float distance2 = abs(Ball_posY - (Paddle_posY + 0.4f));
		float distance3 = abs(Ball_posX - (Paddle_posX + 0.1f));
		float distance4 = abs(Ball_posY - (Paddle_posY));
		float d1 = 0;
		float d2 = 0;
		if (Ball_posX < Paddle_posX) { //circle is left of the left side of rectangle
			d1 = distance1;
		}
		if (Ball_posX > (Paddle_posX + 0.1f)){ //circle is right of the right side of rectangle
			d1 = distance3;
		}
		if (Ball_posY > (Paddle_posY + 0.4f)) { //circle is above of the top side of rectangle
			d2 = distance2;
		}
		if (Ball_posY < (Paddle_posY)) { //circle is below the bottom side of rectangle
			d2 = distance4;
		}
		//std::cout << "[" << Ball_posX << " " << Ball_posY << " " << Paddle_posX << " " << Paddle_posY << " " << distance1 << "]";
		float d = sqrt(pow(d1, 2) + pow(d2, 2));
		if (d <= 0.05f) {
			return true; //collision happened
		}
		else {
			return false; //collision did not happen
		}
	}
};