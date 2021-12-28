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

void Person::draw(double rotationAngle) {
	glPushMatrix();
	glTranslated(this->x, this->y, this->z);
	rotationAngle -= 90;
	if(rotationAngle <= 0)
		rotationAngle = 360 + rotationAngle;
	glRotated(rotationAngle, 0, 1, 0);
	glRotated(180, 0, 1, 0);
	glRotated(10, 0, 1, 0);
	this->gunModel.pos.x = -0.07;
	this->gunModel.pos.y = -0.08;
	this->gunModel.pos.z = -0.02;
	this->gunModel.Draw();
	glPopMatrix();
}