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
	static void drawFan(int fanTex);
	static void drawStorageGlass();
	static void drawRamGlass();
	static void drawCpuGlass();
	static void drawFanGlass();
	static void drawSleepbutton(int sleepTex);
	static void cpuChips(double z , double y);
	static void Capacitor(double x , double z);
	static void drawpices();
	static void drawRamEntrances(int photo);
	static void Room(int room);
};