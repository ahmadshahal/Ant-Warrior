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
	// Top
	glColor3d(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glVertex3d(2, 2.5, -11);
	glVertex3d(16, 2.5, -11);
	glVertex3d(16, 2.5, -14);
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

	// Left
	glColor3d(0.7, 0.7, 0.7);
	glBegin(GL_QUADS);
	glVertex3d(2, 0, -14);
	glVertex3d(2, 0, -11);
	glVertex3d(2, 2.5, -11);
	glVertex3d(2, 2.5, -14);
	glEnd();

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
	
	//glColor3d(1, 1, 1);
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

	// Top
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1, 3.75, -1);
	glTexCoord2d(1, 0);
	glVertex3d(25, 3.75, -1);
	glTexCoord2d(1, 1);
	glVertex3d(25, 3.75, -25);
	glTexCoord2d(0, 1);
	glVertex3d(1, 3.75, -25);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Enviroment::drawSleepbutton(int sleepTex)
{
	glEnable(GL_TEXTURE_2D);

	// Front
	glBindTexture(GL_TEXTURE_2D, sleepTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(16, 1, -24.5);
	glTexCoord2d(1, 0);
	glVertex3d(17, 1, -24.5);
	glTexCoord2d(1, 1);
	glVertex3d(17, 1.5, -24.5);
	glTexCoord2d(0, 1);
	glVertex3d(16, 1.5, -24.5);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glColor3d(1, 1, 1);

	// Top
	glBegin(GL_QUADS);
	glVertex3d(16, 1, -24.5);
	glVertex3d(17, 1, -24.5);
	glVertex3d(17, 1, -25);
	glVertex3d(16, 1, -25);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glVertex3d(16, 1, -24.5);
	glVertex3d(16, 1, -25);
	glVertex3d(16, 1.5, -25);
	glVertex3d(16, 1.5, -24.5);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glVertex3d(17, 1, -24.5);
	glVertex3d(17, 1, -25);
	glVertex3d(17, 1.5, -25);
	glVertex3d(17, 1.5, -24.5);
	glEnd();

	glColor3d(1, 1, 1);
}

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

	glDisable(GL_TEXTURE_2D);
}

void Enviroment::drawRAM(int ramTex)
{
	glEnable(GL_TEXTURE_2D);
	//Left
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19.2, 0, -22);
	glTexCoord2d(1, 0);
	glVertex3d(19.2, 0, -12);
	glTexCoord2d(1, 1);
	glVertex3d(19.2, 1.28, -12);
	glTexCoord2d(0, 1);
	glVertex3d(19.2, 1.28, -22);
	glEnd();
	// Right
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19.5, 0, -22);
	glTexCoord2d(1, 0);
	glVertex3d(19.5, 0, -12);
	glTexCoord2d(1, 1);
	glVertex3d(19.5, 1.28, -12);
	glTexCoord2d(0, 1);
	glVertex3d(19.5, 1.28, -22);
	glEnd();

	// Front
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19.2, 0, -12);
	glTexCoord2d(1, 0);
	glVertex3d(19.5, 0, -12);
	glTexCoord2d(1, 1);
	glVertex3d(19.5, 1.28, -12);
	glTexCoord2d(0, 1);
	glVertex3d(19.2, 1.28, -12);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, ramTex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(19.2, 0, -22);
	glTexCoord2d(1, 0);
	glVertex3d(19.5, 0, -22);
	glTexCoord2d(1, 1);
	glVertex3d(19.5, 1.28, -22);
	glTexCoord2d(0, 1);
	glVertex3d(19.2, 1.28, -22);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glColor3d(1,1,1);

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

void Enviroment::drawFan(int fanTex)
{
	glColor3ub(130, 130, 130);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fanTex);

	for(GLdouble angle = 0; angle < 360; angle += 45) {
		glPushMatrix();
		glRotated(angle, 0, 1, 0);


		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(0, 0, 0);
		glTexCoord2d(1, 0);
		glVertex3d(0, 0, 2);
		glTexCoord2d(1, 1);
		glVertex3d(0, 1.2, 3);
		glTexCoord2d(0, 1);
		glVertex3d(0, 1.2, 0);
		glEnd();

		glPopMatrix();
	}

	glDisable(GL_TEXTURE_2D);

	glColor3d(1, 1, 1);
}

void Enviroment::drawRamGlass(){
	
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Top
	glBegin(GL_QUADS);
	glVertex3d(16, 2.5, -10);
	glVertex3d(23.5, 2.5, -10);
	glVertex3d(23.5, 2.5, -25);
	glVertex3d(16, 2.5, -25);
	glEnd();

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
	
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);
}

void Enviroment::drawStorageGlass(){
    
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Top
	glBegin(GL_QUADS);
	glVertex3d(1, 2.5, -16);
	glVertex3d(15, 2.5, -16);
	glVertex3d(15, 2.5, -25);
	glVertex3d(1, 2.5, -25);
	glEnd();

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
	
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);
}

void Enviroment::drawCpuGlass()
{
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);

	// Top
	glBegin(GL_QUADS);
	glVertex3d(14, 2.5, -1);
	glVertex3d(23.5, 2.5, -1);
	glVertex3d(23.5, 2.5, -9);
	glVertex3d(14, 2.5, -9);
	glEnd();

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
	
	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);

}

void Enviroment::drawFanGlass()
{
	glEnable(GL_BLEND); // Enabling blinding
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1, 1, 1, 0.2);
	// Top
	glBegin(GL_QUADS);
	glVertex3d(-.5, 2.5, -1);
	glVertex3d(8, 2.5, -1);
	glVertex3d(8, 2.5, -9);
	glVertex3d(-.5, 2.5, -9);
	glEnd();

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

	glColor3d(1, 1, 1);
	glDisable(GL_BLEND);
}

void circle(double r, int lats, int longs , int p) {
  float M_PI = 3.14/p;
  int i, j;
  for (i = 0; i <= lats; i++) {
    double lat0 = M_PI * (-0.5 + (double)(i - 1) / lats);
    double z0 = sin(lat0);
    double zr0 = cos(lat0);

    double lat1 = M_PI * (-0.5 + (double)i / lats);
    double z1 = sin(lat1);
    double zr1 = cos(lat1);
    glBegin(GL_QUAD_STRIP);
    for (j = 0; j <= longs; j++) {
      double lng = 2 * M_PI * (double)(j - 1) / longs;
      double x = cos(lng);
      double y = sin(lng);

      glNormal3f(x * zr0, y * zr0, z0);
      glVertex3f(r * x * zr0, r * y * zr0, r * z0);
      glNormal3f(x * zr1, y * zr1, z1);
      glVertex3f(r * x * zr1, r * y * zr1, r * z1);
    }
    glEnd();
  }
}

void Enviroment::cpuChips(double z, double y){
	glPushMatrix();
		glTranslated(17 , 0 , z);
		glColor3ub(255,193,7);
		GLUquadric *quadric = gluNewQuadric();
		gluCylinder(quadric,0.2,0.2,0.1,5,5);
		//circle(0.1,10,10,4);
	glPopMatrix();

	glPushMatrix();
		glTranslated(22 , 0 , z);
		glColor3ub(255,193,7);
		gluCylinder(quadric,0.2,0.2,0.1,5,5);
		//circle(0.1,10,10,4);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(y , 0 , -3);
		glRotatef(120,1,1,1);
		glColor3ub(255,193,7);
		gluCylinder(quadric,0.2,0.2,0.1,5,5);
		//circle(0.1,10,10,4);
	glPopMatrix();

	glPushMatrix();
		glTranslated(y , 0 , -8);
		glRotatef(120,1,1,1);
		glColor3ub(255,193,7);
		gluCylinder(quadric,0.2,0.2,0.1,5,5);
		//circle(0.1,10,10,4);
	glPopMatrix();

	glColor3f(1,1,1);
}

void Enviroment::Capacitor(double x, double z){
	glPushMatrix();
	glTranslatef(x,0,z);
	for(GLdouble angle = 0; angle < 360; angle += 10) {
		glPushMatrix();
		glRotated(angle, 0, 1, 0);
		glLineWidth(5);
		glColor3ub(255,193,7);
		glBegin(GL_LINES);
		glVertex3f(0, 0, 0.18);
		glVertex3f(0, 0.2, 0.18);
		glEnd();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x,0.55,z);
	glRotatef(90,1,0,0);
	glColor3ub(0,0,0);
	GLUquadric *quadric = gluNewQuadric();
	gluCylinder(quadric,0.2,0.2,0.5,20,20);
	glPopMatrix();
	glColor3f(1,1,1);
}

void Enviroment::drawpices(){
	// left 
	glColor3d(0,0,0);
	glBegin(GL_QUADS);
	glVertex3d(19.1, 0.4, -19.8);
	glVertex3d(19.1, 1, -19.8);
	glVertex3d(19.1, 1, -21);
	glVertex3d(19.1, 0.4, -21);
	glEnd();
	//right//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -19.8);
	glVertex3d(19.2, 1, -19.8);
	glVertex3d(19.2, 1, -21);
	glVertex3d(19.2, 0.4, -21);
	glEnd();
	// front // 
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -19.8);
	glVertex3d(19.2, 1, -19.8);
	glVertex3d(19.1, 1, -19.8);
	glVertex3d(19.1, 0.4, -19.8);
	glEnd();
	//back//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -21);
	glVertex3d(19.2, 1, -21);
	glVertex3d(19.1, 1, -21);
	glVertex3d(19.1, 0.4, -21);
	glEnd();
	
   //p2

	//left 
	glBegin(GL_QUADS);
	glVertex3d(19.1, 0.4, -17.8);
	glVertex3d(19.1, 1, -17.8);
	glVertex3d(19.1, 1, -19);
	glVertex3d(19.1, 0.4, -19);
	glEnd();
	//right//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -17.8);
	glVertex3d(19.2, 1, -17.8);
	glVertex3d(19.2, 1, -19);
	glVertex3d(19.2, 0.4, -19);
	glEnd();
	// front // 
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -17.8);
	glVertex3d(19.2, 1, -17.8);
	glVertex3d(19.1, 1, -17.8);
	glVertex3d(19.1, 0.4, -17.8);
	glEnd();
	//back//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -19);
	glVertex3d(19.2, 1, -19);
	glVertex3d(19.1, 1, -19);
	glVertex3d(19.1, 0.4, -19);
	glEnd();
	


 	//p3

	//left 
	glBegin(GL_QUADS);
	glVertex3d(19.1, 0.4, -15);
	glVertex3d(19.1, 1, -15);
	glVertex3d(19.1, 1, -16.2);
	glVertex3d(19.1, 0.4, -16.2);
	glEnd();
	//right//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -15);
	glVertex3d(19.2, 1, -15);
	glVertex3d(19.2, 1, -16.2);
	glVertex3d(19.2, 0.4, -16.2);
	glEnd();
	// front // 
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -15);
	glVertex3d(19.2, 1, -15);
	glVertex3d(19.1, 1, -15);
	glVertex3d(19.1, 0.4, -15);
	glEnd();
	//back//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -16.2);
	glVertex3d(19.2, 1, -16.2);
	glVertex3d(19.1, 1, -16.2);
	glVertex3d(19.1, 0.4, -16.2);
	glEnd();
	
	////p4

	//left
	glBegin(GL_QUADS);
	glVertex3d(19.1, 0.4, -13);
	glVertex3d(19.1, 1, -13);
	glVertex3d(19.1, 1, -14.2);
	glVertex3d(19.1, 0.4, -14.2);
	glEnd();
	//right//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -13);
	glVertex3d(19.2, 1, -13);
	glVertex3d(19.2, 1, -14.2);
	glVertex3d(19.2, 0.4, -14.2);
	glEnd();
	// front // 
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -13);
	glVertex3d(19.2, 1, -13);
	glVertex3d(19.1, 1, -13);
	glVertex3d(19.1, 0.4, -13);
	glEnd();
	//back//
	glBegin(GL_QUADS);
	glVertex3d(19.2, 0.4, -14.2);
	glVertex3d(19.2, 1, -14.2);
	glVertex3d(19.1, 1, -14.2);
	glVertex3d(19.1, 0.4, -14.2);
	glEnd();

    //left P1
	glBegin(GL_QUADS);
	glVertex3d(19.5, 0.4, -19.8);
	glVertex3d(19.5, 1, -19.8);
	glVertex3d(19.5, 1, -21);
	glVertex3d(19.5, 0.4, -21);
	glEnd();
	//right P1
	glBegin(GL_QUADS);
	glTranslatef(1,0,0);
	glVertex3d(19.6, 0.4, -19.8);
	glVertex3d(19.6, 1, -19.8);
	glVertex3d(19.6, 1, -21);
	glVertex3d(19.6, 0.4, -21);
	glEnd();
	// front P1
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -19.8);
	glVertex3d(19.6, 1, -19.8);
	glVertex3d(19.6, 1, -19.8);
	glVertex3d(19.6, 0.4, -19.8);
	glEnd();
	//back P1
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -21);
	glVertex3d(19.6, 1, -21);
	glVertex3d(19.5, 1, -21);
	glVertex3d(19.5, 0.4, -21);
	glEnd();
	//left P2
	glBegin(GL_QUADS);
	glVertex3d(19.5, 0.4, -17.8);
	glVertex3d(19.5, 1, -17.8);
	glVertex3d(19.5, 1, -19);
	glVertex3d(19.5, 0.4, -19);
	glEnd();
	//right P2
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -17.8);
	glVertex3d(19.6, 1, -17.8);
	glVertex3d(19.6, 1, -19);
	glVertex3d(19.6, 0.4, -19);
	glEnd();
	// front P2 
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -17.8);
	glVertex3d(19.6, 1, -17.8);
	glVertex3d(19.5, 1, -17.8);
	glVertex3d(19.5, 0.4, -17.8);
	glEnd();
	//back P2
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -19);
	glVertex3d(19.6, 1, -19);
	glVertex3d(19.5, 1, -19);
	glVertex3d(19.5, 0.4, -19);
	glEnd();

	//left P3
	glBegin(GL_QUADS);
	glVertex3d(19.5, 0.4, -15);
	glVertex3d(19.5, 1, -15);
	glVertex3d(19.5, 1, -16.2);
	glVertex3d(19.5, 0.4, -16.2);
	glEnd();
	//right P3
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -15);
	glVertex3d(19.6, 1, -15);
	glVertex3d(19.6, 1, -16.2);
	glVertex3d(19.6, 0.4, -16.2);
	glEnd();
	// front P3 
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -15);
	glVertex3d(19.6, 1, -15);
	glVertex3d(19.5, 1, -15);
	glVertex3d(19.5, 0.4, -15);
	glEnd();
	//back P3
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -16.2);
	glVertex3d(19.6, 1, -16.2);
	glVertex3d(19.5, 1, -16.2);
	glVertex3d(19.5, 0.4, -16.2);
	glEnd();

	//left P4
	glBegin(GL_QUADS);
	glVertex3d(19.5, 0.4, -13);
	glVertex3d(19.5, 1, -13);
	glVertex3d(19.5, 1, -14.2);
	glVertex3d(19.5, 0.4, -14.2);
	glEnd();
	//right P4
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -13);
	glVertex3d(19.6, 1, -13);
	glVertex3d(19.6, 1, -14.2);
	glVertex3d(19.6, 0.4, -14.2);
	glEnd();
	// front P4
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -13);
	glVertex3d(19.6, 1, -13);
	glVertex3d(19.5, 1, -13);
	glVertex3d(19.5, 0.4, -13);
	glEnd();
	//back P4
	glBegin(GL_QUADS);
	glVertex3d(19.6, 0.4, -14.2);
	glVertex3d(19.6, 1, -14.2);
	glVertex3d(19.5, 1, -14.2);
	glVertex3d(19.5, 0.4, -14.2);
	glEnd();
	glColor3d(1,1,1);

}

void Enviroment::drawRamEntrances(int photo){

	glColor3d(0,1,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,photo);
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19, 0, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(22, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(22, 0.3, -11.8);	
	glTexCoord2d(1,0);
	glVertex3d(19, 0.3, -11.8);
	glEnd();
	
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(22, 0, -12);
	glTexCoord2d(1,1);
	glVertex3d(22, 0.3, -12);
	glTexCoord2d(1,0);
	glVertex3d(19, 0.3, -12);
	glEnd();
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(22, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(22, 0.3, -12);
	glTexCoord2d(1,1);
	glVertex3d(19, 0.3, -12);
	glTexCoord2d(1,0);
	glVertex3d(19, 0.3, -11.8);
	glEnd();
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19, 0, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19, 0.3, -12);
	glTexCoord2d(1,0);
	glVertex3d(19, 0, -12);
	glEnd();
	
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(22.2, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(22.2, 0.3, -22);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0.3, -22);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(22.2, 0, -22.2);
	glTexCoord2d(1,1);
	glVertex3d(22.2, 0.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0.3, -22.2);
	glEnd();
	//top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(22.2, 0.3, -22);
	glTexCoord2d(0,1);
	glVertex3d(22.2, 0.3, -22.2);
	glTexCoord2d(1,1);
	glVertex3d(18.9, 0.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0.3, -22);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(18.9, 0.3, -22);
	glTexCoord2d(1,1);
	glVertex3d(18.9, 0.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0, -22.2);
	glEnd();

	glBegin(GL_QUADS);
	//right
	glTexCoord2d(0,0);
	glVertex3d(19.1, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(19.1, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.1, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.1, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//left
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(18.9, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(18.9, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//top
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.1, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.1, 0.3, -22);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0.3, -22);
	glEnd();
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.1, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.1, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0, -11.8);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.1, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.1, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0, -11.8);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(18.9, 0.3, -22);
	glTexCoord2d(0,1);
	glVertex3d(19.1, 0.3, -22);
	glTexCoord2d(1,1);
	glVertex3d(19.1, 0, -22);
	glTexCoord2d(1,0);
	glVertex3d(18.9, 0, -22);
	glEnd();

	glBegin(GL_QUADS);
	//right
	glTexCoord2d(0,0);
	glVertex3d(22, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(22, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(22, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(22, 0.3, -22.2);
	glEnd();
	glBegin(GL_QUADS);
	//left
	glTexCoord2d(0,0);
	glVertex3d(22.2, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(22.2, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(22.2, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(22.2, 0.3, -22.2);
	glEnd();
	glBegin(GL_QUADS);
	//top
	glTexCoord2d(0,0);
	glVertex3d(22.2, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(22, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(22, 0.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(22.2, 0.3, -22.2);
	
	glEnd();
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(22.2, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(22, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(22, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(22.2, 0, -11.8);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(22.2, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(22, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(22, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(22.2, 0, -11.8);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(22.2, 0.3, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(22, 0.3, -22.2);
	glTexCoord2d(1,1);
	glVertex3d(22, 0, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(22.2, 0, -22.2);
	glEnd();

	glBegin(GL_QUADS);
	//right
	glTexCoord2d(0,0);
	glVertex3d(19.6, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(19.6, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.6, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.6, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//left
	glTexCoord2d(0,0);
	glVertex3d(19.8, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(19.8, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.8, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.8, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//top
	glTexCoord2d(0,0);
	glVertex3d(19.8, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.6, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.6, 0.3, -22);
	glTexCoord2d(1,0);
	glVertex3d(19.8, 0.3, -22);
	glEnd();
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.8, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.6, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.6, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.8, 0, -11.8);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.8, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.6, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.6, 0, -11.8);
    glTexCoord2d(1,0);
	glVertex3d(19.8, 0, -11.8);
	glEnd();

	glBegin(GL_QUADS);
	//right
	glTexCoord2d(0,0);
	glVertex3d(20.4, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(20.4, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.4, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.4, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//left
	glTexCoord2d(0,0);
	glVertex3d(20.6, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(20.6, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.6, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.6, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//top
	glTexCoord2d(0,0);
	glVertex3d(20.6, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(20.4, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.4, 0.3, -22);
	glTexCoord2d(1,0);
	glVertex3d(20.6, 0.3, -22);
	glEnd();
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.6, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(20.4, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.4, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.6, 0, -11.8);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.6, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(20.4, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.4, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.6, 0, -11.8);
	glEnd();
	
	glBegin(GL_QUADS);
	//right
	glTexCoord2d(0,0);
	glVertex3d(21.2, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(21.2, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.2, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.2, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//left
	glTexCoord2d(0,0);
	glVertex3d(21.4, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(21.4, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.4, 0.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.4, 0.3, -22);
	glEnd();
	glBegin(GL_QUADS);
	//top
	glTexCoord2d(0,0);
	glVertex3d(21.4, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.2, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.2, 0.3, -22);
	glTexCoord2d(1,0);
	glVertex3d(21.4, 0.3, -22);
	glEnd();
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.4, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.2, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.2, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.4, 0, -11.8);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.4, 0.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.2, 0.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.2, 0, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.4, 0, -11.8);
	glEnd();
	
	// Front
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 0, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1.3, -11.8);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);	
	glVertex3d(19.2, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 0, -12);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1, -12);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(19.2, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.2, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1, -12);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.5, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(19.5, 1, -12);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 1.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 1.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1, -12);
	glEnd();

	// Front
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 0, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20, 1.3, -11.8);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 0, -12);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(20, 1, -12);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(20, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20, 1, -12);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.3, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.3, 1, -12);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 1.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 1.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(20, 1, -12);
	glEnd();

	// Front
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 0, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1.3, -11.8);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 0, -12);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1, -12);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(20.8, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(20.8, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1, -12);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.1, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.1, 1, -12);
	glEnd();
	

	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 1.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 1.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1, -12);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 0, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1.3, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1.3, -11.8);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 0, -12);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1, -12);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(21.6, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.6, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1, -12);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.9, 0, -12);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 0, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1, -11.8);
	glTexCoord2d(1,0);
	glVertex3d(21.9, 1, -12);
	glEnd();
	
	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 1.3, -11.8);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 1.3, -11.8);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1, -12);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1, -12);
	glEnd();
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,photo);

	// Front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1, -22);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 0, -22.2);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1.3, -22.2);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(19.2, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(19.2, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1, -22.2);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.5, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(19.5, 1, -22.2);
	glEnd();
	

	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(19.2, 1, -22);
	glTexCoord2d(0,1);
	glVertex3d(19.5, 1, -22);
	glTexCoord2d(1,1);
	glVertex3d(19.5, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(19.2, 1.3, -22.2);
	glEnd();

	// Front
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(20, 1, -22);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 0, -22.2);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(20, 1.3, -22.2);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(20, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(20, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(20, 1, -22.2);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.3, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(20.3, 1, -22.2);
	glEnd();


	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20, 1, -22);
	glTexCoord2d(0,1);
	glVertex3d(20.3, 1, -22);
	glTexCoord2d(1,1);
	glVertex3d(20.3, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(20, 1.3, -22.2);
	glEnd();


	///////////colum right3
	// Front
	
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
	glVertex3d(20.8, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1, -22);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 0, -22.2);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1.3, -22.2);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(20.8, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(20.8, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1, -22.2);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.1, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(21.1, 1, -22.2);
	glEnd();
	

	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(20.8, 1, -22);
	glTexCoord2d(0,1);
	glVertex3d(21.1, 1, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.1, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(20.8, 1.3, -22.2);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 0, -22);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1, -22);
	glEnd();

	// Back
	
	glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3d(21.6, 0, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(21.9, 0, -22.2);
	glTexCoord2d(0,0);
	glVertex3d(21.9, 1.3, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(21.6, 1.3, -22.2);
	glEnd();

	//Left
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(21.6, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.6, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1, -22.2);
	glEnd();
	// Right
	
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.9, 0, -22.2);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 0, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1, -22);
	glTexCoord2d(1,0);
	glVertex3d(21.9, 1, -22.2);
	glEnd();
	

	// Top
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(21.6, 1, -22);
	glTexCoord2d(0,1);
	glVertex3d(21.9, 1, -22);
	glTexCoord2d(1,1);
	glVertex3d(21.9, 1.3, -22.2);
	glTexCoord2d(1,0);
	glVertex3d(21.6, 1.3, -22.2);
	glEnd();
	 glDisable(GL_TEXTURE_2D);
 }