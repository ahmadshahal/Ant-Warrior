#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include "ant.h"
#include "collision.h"

Ant::Ant(GLdouble x, GLdouble y, GLdouble z) {
	handleBorder();
	this->x = x;
	this->y = y;
	this->z = z;
	this->moveForward = 1;
	this->moveRight = 1;
	this->rotationAngle = 0 + (double)(rand()) / ((double)(RAND_MAX / (360 - (0))));
	this->antModel = Model_3DS();
	this->antTex.LoadBMP("media/black.bmp");
	this->antModel.Load("media/ant.3ds");
	this->antModel.Materials[0].tex = this->antTex;
	this->antModel.scale = 0.01 * 140;
}

void Ant::draw() {
	glPushMatrix();
	glTranslated(this->x, this->y, this->z);
	glRotated(this->rotationAngle, 0, 1, 0);
	this->antModel.pos.x = 0;
	this->antModel.pos.y = 0;
	this->antModel.pos.z = 0;
	this->antModel.Draw();
	glPopMatrix();
}

void Ant::move(GLdouble myX, GLdouble myZ) {

	myX -= this->x;
	myZ -= this->z;
	GLdouble toAddX = 0.0007 * myX;
	GLdouble toAddZ = 0.0007 * myZ;
	GLdouble newX = this->x + toAddX;
	GLdouble newZ = this->z + toAddZ;
	if(border[(int) floor(newX)][abs((int) floor(newZ))]) {
		this->x = newX;
		this->z = newZ;
	}

	/*
	int random = rand() % 2;
	if(random == 0) {
		if(moveForward) {
			if(border[(int) (this->x + 0.2)][abs((int) this->z)]) {
				this->x += 0.2;
			}
			else {
				moveForward = !moveForward;
			}
		}
		else {
			if(border[(int) (this->x - 0.2)][abs((int) this->z)]) {
				this->x -= 0.2;
			}
			else {
				moveForward = !moveForward;
			}
		}
	}
	else {
		if(moveRight) {
			if(border[(int) this->x][(int) (abs((int) this->z + 0.2))]) {
				this->z += 0.2;
			}
			else {
				moveRight = !moveRight;
			}
		}
		else {
			if(border[(int) this->x][(int) (abs((int) this->z - 0.2))]) {
				this->z -= 0.2;
			}
			else {
				moveRight = !moveRight;
			}
		}
	}
	*/
}