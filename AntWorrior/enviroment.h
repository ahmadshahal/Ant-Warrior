#pragma once

class Enviroment
{
public:
	static void drawGPU(int frontTex, int backTex);
	static void drawMotherBoard(int bottomTex, int wallTex);
	static void drawCPU(int cpuTex);
	static void drawSSD(int ssdTex);
	static void drawRAM(int ramTex);
	static void drawMonitor(int desktopTex);
	static void drawPin();
	static void drawFan();
	static void drawStorageGlass();
	static void drawRamGlass();
	static void drawCpuGlass();
	static void drawFanGlass();
	static void drawX(GLdouble x, GLdouble y, GLdouble z);
};