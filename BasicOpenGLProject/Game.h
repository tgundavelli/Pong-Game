#pragma once

#include <iostream>
#include <string>
#include <GL/freeglut.h>

class Game {
protected :
	int Userscore;
	int Otherscore;
	bool UserPush;
	bool OtherPush;
	bool OppWallUser;
	bool OppWallOther;
public:
	Game() {
		Userscore = 0;
		Otherscore = 0;
		UserPush = false;
		OtherPush = false;
		OppWallUser = false;
		OppWallOther = false;
	}
	void reset_bools() {
		UserPush = false;
		OtherPush = false;
		OppWallUser = false;
		OppWallOther = false;
	}
	~Game() {

	}
	void ScoreRender() {
		//glClear(GL_COLOR_BUFFER_BIT); don't use this or else it can't exist at same time as dashed lines

		std::string str1 = std::to_string(Userscore);
		const unsigned char* string1 = reinterpret_cast<const unsigned char*>(str1.c_str());
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos2f(-0.25, 0.9);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, string1);

		std::string str2 = std::to_string(Otherscore);
		const unsigned char* string2 = reinterpret_cast<const unsigned char*>(str2.c_str());
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos2f(0.25, 0.9);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, string2);


	}
	void set_UP(bool w){
		UserPush = w;
	}
	void set_OP(bool x) {
		OtherPush = x;
	}
	void set_OPU(bool y) {
		OppWallUser = y;
	}
	void set_OPO(bool z) {
		OppWallOther = z;
	}
	void CalculateScore() {
		std::cout << UserPush << OppWallUser << OtherPush << OppWallOther << " ";
		if (UserPush && OppWallUser) {
			Userscore++;
		}
		if (OtherPush && OppWallOther) {
			Otherscore++;
		}
	}
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