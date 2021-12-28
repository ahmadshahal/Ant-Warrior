#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include <windows.h> // Header File For Windows
#include <gl/gl.h>   // Header File For The OpenGL32 Library
#include <gl/glu.h>
#include <cmath>
#include <texture.h>
#include "enviroment.h"

void Enviroment::drawGPU(int frontTex, int backText)
{
	glEnable(GL_TEXTURE_2D);

	// Front
	glBindTexture(GL_TEXTURE_2D, frontTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(2, 0, -11);
	glTexCoord2d(1, 0);
	glVertex3d(16, 0, -11);
	glTexCoord2d(1, 1);
	glVertex3d(16, 2.5, -11);
	glTexCoord2d(0, 1);
	glVertex3d(2, 2.5, -11);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, backText);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(2, 0, -14);
	glTexCoord2d(1, 0);
	glVertex3d(16, 0, -14);
	glTexCoord2d(1, 1);
	glVertex3d(16, 2.5, -14);
	glTexCoord2d(0, 1);
	glVertex3d(2, 2.5, -14);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	// Left
	glColor3d(0.7, 0.7, 0.7);
	glBegin(GL_QUADS);
	glVertex3d(2, 0, -14);
	glVertex3d(2, 0, -11);
	glVertex3d(2, 2.5, -11);
	glVertex3d(2, 2.5, -14);
	glEnd();
  
	// Right
	glBegin(GL_QUADS);
	glVertex3d(16, 1.5, -14);
	glVertex3d(16, 1.5, -11);
	glVertex3d(16, 2.5, -11);
	glVertex3d(16, 2.5, -14);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(16, 0, -12.5);
	glVertex3d(16, 0, -11);
	glVertex3d(16, 1.5, -11);
	glVertex3d(16, 1.5, -12.5);
	glEnd();
	
	// Top
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glVertex3d(2, 2.5, -11);
	glVertex3d(16, 2.5, -11);
	glVertex3d(16, 2.5, -14);
	glVertex3d(2, 2.5, -14);
	glEnd();
	glColor3d(1, 1, 1);
}

void Enviroment::drawMotherBoard(int bottomTex, int wallTex)
{
	glEnable(GL_TEXTURE_2D);

	// Front
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0, -1);
	glTexCoord2d(1, 0);
	glVertex3d(25, 0, -1);
	glTexCoord2d(1, 1);
	glVertex3d(25, 3.75, -1);
	glTexCoord2d(0, 1);
	glVertex3d(1, 3.75, -1);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0, -25);
	glTexCoord2d(1, 0);
	glVertex3d(25, 0, -25);
	glTexCoord2d(1, 1);
	glVertex3d(25, 3.75, -25);
	glTexCoord2d(0, 1);
	glVertex3d(1, 3.75, -25);
	glEnd();

	// Left
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0, -25);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0, -1);
	glTexCoord2d(1, 1);
	glVertex3d(1, 3.75, -1);
	glTexCoord2d(0, 1);
	glVertex3d(1, 3.75, -25);
	glEnd();

	// Right
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(25, 0, -25);
	glTexCoord2d(1, 0);
	glVertex3d(25, 0, -1);
	glTexCoord2d(1, 1);
	glVertex3d(25, 3.75, -1);
	glTexCoord2d(0, 1);
	glVertex3d(25, 3.75, -25);
	glEnd();

	// Bottom
	glBindTexture(GL_TEXTURE_2D, bottomTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0, -1);
	glTexCoord2d(1, 0);
	glVertex3d(25, 0, -1);
	glTexCoord2d(1, 1);
	glVertex3d(25, 0, -25);
	glTexCoord2d(0, 1);
	glVertex3d(1, 0, -25);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

// 1st Version:
/*
void Enviroment::drawCPU(int cpuTex)
{
	glEnable(GL_TEXTURE_2D);

	// Front
	glBindTexture(GL_TEXTURE_2D, cpuTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(17, 0, -3);
	glTexCoord2d(1, 0);
	glVertex3d(22, 0, -3);
	glTexCoord2d(1, 1);
	glVertex3d(22, 2.5, -3);
	glTexCoord2d(0, 1);
	glVertex3d(17, 2.5, -3);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, cpuTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(17, 0, -8);
	glTexCoord2d(1, 0);
	glVertex3d(22, 0, -8);
	glTexCoord2d(1, 1);
	glVertex3d(22, 2.5, -8);
	glTexCoord2d(0, 1);
	glVertex3d(17, 2.5, -8);
	glEnd();

	// Left
	glBindTexture(GL_TEXTURE_2D, cpuTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(17, 0, -8);
	glTexCoord2d(1, 0);
	glVertex3d(17, 0, -3);
	glTexCoord2d(1, 1);
	glVertex3d(17, 2.5, -3);
	glTexCoord2d(0, 1);
	glVertex3d(17, 2.5, -8);
	glEnd();

	// Right
	glBindTexture(GL_TEXTURE_2D, cpuTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(22, 0, -8);
	glTexCoord2d(1, 0);
	glVertex3d(22, 0, -3);
	glTexCoord2d(1, 1);
	glVertex3d(22, 2.5, -3);
	glTexCoord2d(0, 1);
	glVertex3d(22, 2.5, -8);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
*/

void Enviroment::drawCPU(int cpuTex)
{
	glColor3ub(150, 150, 150);

	// Front
	glBegin(GL_QUADS);
	glVertex3d(17, 0, -3);
	glVertex3d(22, 0, -3);
	glVertex3d(22, 0.25, -3);
	glVertex3d(17, 0.25, -3);
	glEnd();

	// Back
	glBegin(GL_QUADS);
	glVertex3d(17, 0, -8);
	glVertex3d(22, 0, -8);
	glVertex3d(22, 0.25, -8);
	glVertex3d(17, 0.25, -8);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glVertex3d(17, 0, -8);
	glVertex3d(17, 0, -3);
	glVertex3d(17, 0.25, -3);
	glVertex3d(17, 0.25, -8);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glVertex3d(22, 0, -8);
	glVertex3d(22, 0, -3);
	glVertex3d(22, 0.25, -3);
	glVertex3d(22, 0.25, -8);
	glEnd();

	glColor3d(1, 1, 1);

	// Top
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, cpuTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(17, 0.25, -3);
	glTexCoord2d(1, 0);
	glVertex3d(22, 0.25, -3);
	glTexCoord2d(1, 1);
	glVertex3d(22, 0.25, -8);
	glTexCoord2d(0, 1);
	glVertex3d(17, 0.25, -8);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Enviroment::drawSSD(int ssdTex)
{
	glEnable(GL_TEXTURE_2D);

	// Front
	glBindTexture(GL_TEXTURE_2D, ssdTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(3, 0, -17);
	glTexCoord2d(1, 0);
	glVertex3d(4, 0, -17);
	glTexCoord2d(1, 1);
	glVertex3d(4, 1.25, -17);
	glTexCoord2d(0, 1);
	glVertex3d(3, 1.25, -17);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, ssdTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(3, 0, -23);
	glTexCoord2d(1, 0);
	glVertex3d(4, 0, -23);
	glTexCoord2d(1, 1);
	glVertex3d(4, 1.25, -23);
	glTexCoord2d(0, 1);
	glVertex3d(3, 1.25, -23);
	glEnd();

	// Left
	glBindTexture(GL_TEXTURE_2D, ssdTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(3, 0, -23);
	glTexCoord2d(1, 0);
	glVertex3d(3, 0, -17);
	glTexCoord2d(1, 1);
	glVertex3d(3, 1.25, -17);
	glTexCoord2d(0, 1);
	glVertex3d(3, 1.25, -23);
	glEnd();

	// Right
	glBindTexture(GL_TEXTURE_2D, ssdTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(4, 0, -23);
	glTexCoord2d(1, 0);
	glVertex3d(4, 0, -17);
	glTexCoord2d(1, 1);
	glVertex3d(4, 1.25, -17);
	glTexCoord2d(0, 1);
	glVertex3d(4, 1.25, -23);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glColor3d(0, 0, 0);

	// Top
	glBegin(GL_QUADS);
	glVertex3d(3, 1.25, -17);
	glVertex3d(4, 1.25, -17);
	glVertex3d(4, 1.25, -23);
	glVertex3d(3, 1.25, -23);
	glEnd();

	glColor3d(1, 1, 1);
}

void Enviroment::drawRAM(int ramTex)
{
	glEnable(GL_TEXTURE_2D);

	// Front
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19, 0, -11);
	glTexCoord2d(1, 0);
	glVertex3d(19.5, 0, -11);
	glTexCoord2d(1, 1);
	glVertex3d(19.5, 1.25, -11);
	glTexCoord2d(0, 1);
	glVertex3d(19, 1.25, -11);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19, 0, -23);
	glTexCoord2d(1, 0);
	glVertex3d(19.5, 0, -23);
	glTexCoord2d(1, 1);
	glVertex3d(19.5, 1.25, -23);
	glTexCoord2d(0, 1);
	glVertex3d(19, 1.25, -23);
	glEnd();

	// Left
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19, 0, -23);
	glTexCoord2d(1, 0);
	glVertex3d(19, 0, -11);
	glTexCoord2d(1, 1);
	glVertex3d(19, 1.25, -11);
	glTexCoord2d(0, 1);
	glVertex3d(19, 1.25, -23);
	glEnd();

	// Right
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19.5, 0, -23);
	glTexCoord2d(1, 0);
	glVertex3d(19.5, 0, -11);
	glTexCoord2d(1, 1);
	glVertex3d(19.5, 1.25, -11);
	glTexCoord2d(0, 1);
	glVertex3d(19.5, 1.25, -23);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	glColor3d(0, 0, 0);

	// Top
	glBegin(GL_QUADS);
	glVertex3d(19, 1.25, -11);
	glVertex3d(19.5, 1.25, -11);
	glVertex3d(19.5, 1.25, -23);
	glVertex3d(19, 1.25, -23);
	glEnd();
	
	glColor3d(1, 1, 1);
}

void Enviroment::drawMonitor(int desktopTex)
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, desktopTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(26, 4.375, -25);
	glTexCoord2d(1, 0);
	glVertex3d(26, 4.375, -1);
	glTexCoord2d(1, 1);
	glVertex3d(26, 13.75, -1);
	glTexCoord2d(0, 1);
	glVertex3d(26, 13.75, -25);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Enviroment::drawPin()
{
	glColor3d(0.8, 0.8, 0.8);

	// Front
	glBegin(GL_QUADS);
	glVertex3d(11, 0, -4);
	glVertex3d(12, 0, -4);
	glVertex3d(12, 0.5, -4);
	glVertex3d(11, 0.5, -4);
	glEnd();

	// Back
	glBegin(GL_QUADS);
	glVertex3d(11, 0, -5);
	glVertex3d(12, 0, -5);
	glVertex3d(12, 0.5, -5);
	glVertex3d(11, 0.5, -5);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glVertex3d(11, 0, -5);
	glVertex3d(11, 0, -4);
	glVertex3d(11, 0.5, -4);
	glVertex3d(11, 0.5, -5);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glVertex3d(12, 0, -5);
	glVertex3d(12, 0, -4);
	glVertex3d(12, 0.5, -4);
	glVertex3d(12, 0.5, -5);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glVertex3d(11, 0.5, -4);
	glVertex3d(12, 0.5, -4);
	glVertex3d(12, 0.5, -5);
	glVertex3d(11, 0.5, -5);
	glEnd();

	glColor3d(1, 1, 1);
}

void Enviroment::drawFan()
{

	// Drawn at (0, 0, 0) because the center has been
	// translated to its position.

	glColor3ub(130, 130, 130);

	for(GLdouble angle = 0; angle < 360; angle += 45) {
		glPushMatrix();
		glRotated(angle, 0, 1, 0);


		glBegin(GL_QUADS);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 2);
		glVertex3d(0, 1.2, 3);
		glVertex3d(0, 1.2, 0);
		glEnd();

		glPopMatrix();
	}

	glColor3d(1, 1, 1);
}

void Enviroment::drawRamGlass(){
	
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Front
	glBegin(GL_QUADS);
	glVertex3d(17.5, 0, -10);
	glVertex3d(23.5, 0, -10);
	glVertex3d(23.5, 2.5, -10);
	glVertex3d(17.5, 2.5, -10);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(16, 1.5, -10);
	glVertex3d(17.5, 1.5, -10);
	glVertex3d(17.5, 2.5, -10);
	glVertex3d(16, 2.5, -10);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glVertex3d(16, 0, -10);
	glVertex3d(16, 0, -25);
	glVertex3d(16, 2.5, -25);
	glVertex3d(16, 2.5, -10);
	glEnd();
	
	// Top
	glBegin(GL_QUADS);
	glVertex3d(16, 2.5, -10);
	glVertex3d(23.5, 2.5, -10);
	glVertex3d(23.5, 2.5, -25);
	glVertex3d(16, 2.5, -25);
	glEnd();
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);
}

void Enviroment::drawStorageGlass(){
    
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Front
	glBegin(GL_QUADS);
	glVertex3d(1, 0, -16);
	glVertex3d(13.5, 0, -16);
	glVertex3d(13.5, 2.5, -16);
	glVertex3d(1, 2.5, -16);
	glEnd();   
	glBegin(GL_QUADS);
	glVertex3d(13.5, 1.5, -16);
	glVertex3d(15, 1.5, -16);
	glVertex3d(15, 2.5, -16);
	glVertex3d(13.5, 2.5, -16);
	glEnd();
	
	// Right
	glBegin(GL_QUADS);
	glVertex3d(15, 0, -16);
	glVertex3d(15, 0, -25);
	glVertex3d(15, 2.5, -25);
	glVertex3d(15, 2.5, -16);
	glEnd();  
	
	// Top
	glBegin(GL_QUADS);
	glVertex3d(1, 2.5, -16);
	glVertex3d(15, 2.5, -16);
	glVertex3d(15, 2.5, -25);
	glVertex3d(1, 2.5, -25);
	glEnd();
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);
}

void Enviroment::drawCpuGlass()
{
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Left
	glBegin(GL_QUADS);
	glVertex3d(14, 0, -1);
	glVertex3d(14, 0, -8);
	glVertex3d(14, 2.5, -8);
	glVertex3d(14, 2.5, -1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(14, 1.5, -8);
	glVertex3d(14, 1.5, -9);
	glVertex3d(14, 2.5, -9);
	glVertex3d(14, 2.5, -8);
	glEnd();

	// Back
	glBegin(GL_QUADS);
	glVertex3d(14, 0, -9);
	glVertex3d(23.5, 0, -9);
	glVertex3d(23.5, 2.5, -9);
	glVertex3d(14, 2.5, -9);
	glEnd();
	
	// Top
	glBegin(GL_QUADS);
	glVertex3d(14, 2.5, -1);
	glVertex3d(23.5, 2.5, -1);
	glVertex3d(23.5, 2.5, -9);
	glVertex3d(14, 2.5, -9);
	glEnd();
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);

}

void Enviroment::drawFanGlass()
{
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Back
	glBegin(GL_QUADS);
	glVertex3d(-.5, 0, -9);
	glVertex3d(8, 0, -9);
	glVertex3d(8, 2.5, -9);
	glVertex3d(-.5, 2.5, -9);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glVertex3d(8, 0, -1);
	glVertex3d(8, 0, -8);
	glVertex3d(8, 2.5, -8);
	glVertex3d(8, 2.5, -1);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(8, 1.5, -8);
	glVertex3d(8, 1.5, -9);
	glVertex3d(8, 2.5, -9);
	glVertex3d(8, 2.5, -8);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glVertex3d(-.5, 2.5, -1);
	glVertex3d(8, 2.5, -1);
	glVertex3d(8, 2.5, -9);
	glVertex3d(-.5, 2.5, -9);
	glEnd();
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);
}

void Enviroment::drawX(GLdouble x, GLdouble y, GLdouble z, double rotationAngle)
{
	glLineWidth(2);
	glPushMatrix();
	glTranslated(x, y, z);
	rotationAngle -= 90;
	if(rotationAngle <= 0)
		rotationAngle = 360 + rotationAngle;
	glRotated(rotationAngle, 0, 1, 0);
	glRotated(45, 0, 0, 1);
	glBegin(GL_LINES);

	glVertex3d(0 - 0.004, 0, 0);
	glVertex3d(0 + 0.004, 0, 0);
	
	glVertex3d(0, 0 - 0.004, 0);
	glVertex3d(0, 0 + 0.004, 0);

	glEnd();
	glPopMatrix();
}