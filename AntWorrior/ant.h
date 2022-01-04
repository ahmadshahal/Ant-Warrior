#define _CRT_SECURE_NO_DEPRECATE
#pragma once

#include <windows.h> // Header File For Windows
#include <gl/gl.h>   // Header File For The OpenGL32 Library
#include <gl/glut.h> // Header File For The GLu32 Library
#include <gl/glu.h>
#include <random>
#include "3DTexture.h"
#include "Model_3DS.h"

class Ant {
public:
	GLdouble x, y, z;
	GLdouble rotationAngle;
	bool moveForward;
	bool moveRight;
	GLTexture antTex;
	Model_3DS antModel;
	Ant(GLdouble x, GLdouble y, GLdouble z);
	void draw();
	void move(GLdouble myX, GLdouble myZ);
};