#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include "ant.h"

Ant::Ant(GLdouble x, GLdouble y, GLdouble z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->rotationAngle = 0 + (double)(rand()) / ((double)(RAND_MAX / (360 - (0))));
	this->antModel = Model_3DS();
	this->antTex.LoadBMP("media/ant.bmp");
	this->antModel.Load("media/ant.3ds");
	this->antModel.Materials[0].tex = this->antTex;
	this->antModel.scale = 0.01;
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

void Ant::move() {
	
}