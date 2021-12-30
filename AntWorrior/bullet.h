#define _CRT_SECURE_NO_DEPRECATE
#pragma once

#include <windows.h> // Header File For Windows
#include <gl/gl.h>   // Header File For The OpenGL32 Library
#include <gl/glut.h> // Header File For The GLu32 Library
#include <gl/glu.h>
#include <math.h>

class Bullet {
public:
	GLdouble x, y, z;
	GLdouble lookX, lookY, lookZ;
	double counter;
	Bullet(GLdouble x, GLdouble y, GLdouble z, GLdouble lookX, GLdouble lookY, GLdouble lookZ);
	void draw();
	void move();
};