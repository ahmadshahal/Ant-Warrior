#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include "bullet.h"
#include "utility.h"

Bullet::Bullet(GLdouble x, GLdouble y, GLdouble z, GLdouble lookX, GLdouble lookY, GLdouble lookZ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->lookX = lookX;
	this->lookY = lookY;
	this->lookZ = lookZ;
	this->counter = 0;
}

void Bullet::draw() {
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslated(this->x, this->y, this->z);
	drawSphere(1, 20, 20);
	glPopMatrix();
}

void Bullet::move() {
	counter += 0.05;
	this->x = (this->x) + (this->lookX * counter);
	this->y = (this->y) + (this->lookY * counter);
	this->z = (this->z) + (this->lookZ * counter);
}

