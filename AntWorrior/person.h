#define _CRT_SECURE_NO_DEPRECATE
#pragma once

#include <windows.h> // Header File For Windows
#include <gl/gl.h>   // Header File For The OpenGL32 Library
#include <gl/glut.h> // Header File For The GLu32 Library
#include <gl/glu.h>
#include "3DTexture.h"
#include "Model_3DS.h"

class Person {
public:
	GLdouble x, y, z;
	GLTexture gunTex;
	Model_3DS gunModel;
	Person(GLdouble x, GLdouble y, GLdouble z);
	void draw(double horizontalAngle, double verticalAngle);
};