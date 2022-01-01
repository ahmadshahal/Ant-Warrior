#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include "person.h"

Person::Person() {
	this->gunModel = Model_3DS();
	this->gunTex.LoadBMP("media/gun.bmp");
	this->gunModel.Load("media/gun.3ds");
	this->gunModel.Materials[3].tex = this->gunTex;
	this->gunModel.scale = 0.22;
}

void Person::draw() {
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glRotated(10, 0, 1, 0);
	this->gunModel.pos.x = -10;
	this->gunModel.pos.y = -5;
	this->gunModel.pos.z = 20;
	this->gunModel.Draw();
	glPopMatrix();
}

void Person::drawX()
{
	glLineWidth(2);
	glPushMatrix();
	glRotated(45, 0, 0, 1);
	glBegin(GL_LINES);

	glVertex3d(0 - 0.01, 0, -1);
	glVertex3d(0 + 0.01, 0, -1);
	
	glVertex3d(0, 0 - 0.01, -1);
	glVertex3d(0, 0 + 0.01, -1);

	glEnd();
	glPopMatrix();
}