#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include "person.h"

Person::Person(GLdouble x, GLdouble y, GLdouble z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->gunModel = Model_3DS();
	this->gunTex.LoadBMP("media/gun.bmp");
	this->gunModel.Load("media/gun.3ds");
	this->gunModel.Materials[3].tex = this->gunTex;
	this->gunModel.scale = 0.003;
}

void Person::draw(double horizontalAngle, double verticalAngle) {
	glPushMatrix();
	glTranslated(this->x, this->y, this->z);
	horizontalAngle -= 90;
	if(horizontalAngle <= 0)
		horizontalAngle = 360 + horizontalAngle;
	glRotated(horizontalAngle, 0, 1, 0);
	glRotated(verticalAngle, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	glRotated(10, 0, 1, 0);
	this->gunModel.pos.x = -0.1;
	this->gunModel.pos.y = -0.08;
	this->gunModel.pos.z = -0.02;
	this->gunModel.Draw();
	glPopMatrix();
}