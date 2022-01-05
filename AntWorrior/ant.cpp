#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include "ant.h"
#include "collision.h"

#define SQR(x) (x*x)


Ant::Ant(GLdouble x, GLdouble y, GLdouble z) {
	handleBorder();
	this->x = x;
	this->y = y;
	this->z = z;
	this->moveForward = 1;
	this->moveRight = 1;
	this->rotationAngle = 0;
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

	const float CONSTANT = (180.0 / 3.141592653589793238463);
	float length = (sqrt(SQR(myX) + SQR(myZ)));
	GLdouble myNewX = myX / length;
	GLdouble myNewZ = (myZ / length) * -1;
	float angle = atan2(myNewZ, myNewX);
	this->rotationAngle = (angle * CONSTANT) + 270;

	GLdouble toAddX = 0.001 * myX;
	GLdouble toAddZ = 0.001 * myZ;
	GLdouble newX = this->x + toAddX;
	GLdouble newZ = this->z + toAddZ;
	if(border[(int) floor(newX)][abs((int) floor(newZ))]) {
		this->x = newX;
		this->z = newZ;
	}
}