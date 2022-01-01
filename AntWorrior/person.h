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
	GLTexture gunTex;
	Model_3DS gunModel;
	Person();
	void draw();
	void drawX();
};