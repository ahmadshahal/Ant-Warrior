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
	this->gunModel.Materials[0].tex = this->gunTex;
	this->gunModel.scale = 0.004;
}

void Person::draw() {
	glPushMatrix();
	glTranslated(this->x, this->y, this->z);
	glRotated(180, 0, 1, 0);
	glRotated(10, 0, 1, 0);
	this->gunModel.pos.x = 0;
	this->gunModel.pos.y = 0;
	this->gunModel.pos.z = 0;
	this->gunModel.Draw();
	glPopMatrix();
}