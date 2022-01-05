#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include <windows.h> // Header File For Windows
#include <gl/gl.h>   // Header File For The OpenGL32 Library
#include <gl/glu.h>  // Header File For The GLu32 Library
// #include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <set>
#include <texture.h>
#include <time.h>
#include <random>
#include "camera.h"
#include "collision.h"
#include "Sound.h"
#include "enviroment.h"
#include "ant.h"
#include "person.h"
#include "bullet.h"
using namespace std;

// ======================================================================================
// =================================OUR VARIABLES========================================

set<Ant*> ants;
set<Bullet*> bullets;
int initialNumOfAnts = 15;

Person* person;

int SCALE = 140;
bool canFire = true;

Camera myCamera;
int mouseX = 0, mouseY = 0;
bool isLClicked = 0, isRClicked = 0;

// ======================================================================================


// ======================================================================================
int motherBoardBottomTex, motherBoardWall;
int ramTex, gpuFront, gpuBack, cpuTex, ssdTex, ramTex2, fanTex, buttonTex;
double fanRotate = 0;
bool shootingSoundIsPlaying = false;
time_t shootingSoundStartTime;

INIT initialize = INIT(); // Sound Initialize
Sound shootingSound;

GLUquadric *quadric = gluNewQuadric();

bool enableLight = true;
GLfloat pos [] = {1750, 525, -1750, 1};
GLfloat ambient [] = {1, 1, 1, 1};
GLfloat diffues [] = {1, 1, 1, 1};
GLfloat specular [] = {0, 0, 0, 1};
GLfloat shin [] = {90};

HDC hDC = NULL;      // Private GDI Device Context
HGLRC hRC = NULL;    // Permanent Rendering Cntext
HWND hWnd = NULL;    // Holds Our Window Handle
HINSTANCE hInstance; // Holds The Instance Of The Application

bool keys[256];          // Array Used For The Keyboard Routine
bool active = TRUE;      // Window Active Flag Set To TRUE By Default
bool fullscreen = FALSE; // Fullscreen Flag Set To Fullscreen Mode By Default

GLvoid ReSizeGLScene(GLsizei width, GLsizei height) // Resize And Initialize The GL Window
{
	if (height == 0) // Prevent A Divide By Zero By
	{
		height = 1; // Making Height Equal One
	}

	glViewport(0, 0, width, height); // Reset The Current Viewport

	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity();            // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200000.0f);

	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity();           // Reset The Modelview Matrix
}

void initAnts() {
	for(int i = 0; i < initialNumOfAnts; i++) {
		while(true) {
			int x = 2 + (double)(rand()) / ((double)(RAND_MAX / (24 - (2))));
			int z = abs(-24 + (double)(rand()) / ((double)(RAND_MAX / (-2 - (-24)))));
			if(border[x * SCALE][z * SCALE] != 0 && border[x * SCALE][z * SCALE] != 2
				&& border[x * SCALE + 10][z * SCALE] != 0 && border[x * SCALE + 10][z * SCALE] != 2
				&& border[x * SCALE - 10][z * SCALE] != 0 && border[x * SCALE - 10][z * SCALE] != 2
				&& border[x * SCALE][z * SCALE + 10] != 0 && border[x * SCALE][z * SCALE + 10] != 2
				&& border[x * SCALE][z * SCALE - 10] != 0 && border[x * SCALE][z * SCALE - 10] != 2
				&& border[x * SCALE + 10][z * SCALE + 10] != 0 && border[x * SCALE + 10][z * SCALE + 10] != 2
				&& border[x * SCALE - 10][z * SCALE - 10] != 0 && border[x * SCALE - 10][z * SCALE - 10] != 2
				&& border[x * SCALE + 10][z * SCALE - 10] != 0 && border[x * SCALE + 10][z * SCALE - 10] != 2
				&& border[x * SCALE - 10][z * SCALE + 10] != 0 && border[x * SCALE - 10][z * SCALE + 10] != 2
				&& (z * SCALE > myCamera.Position.z + 4 * SCALE * -1
				|| z * SCALE < myCamera.Position.z - 4 * SCALE * -1
				|| x * SCALE > myCamera.Position.x + 4 * SCALE
				|| x * SCALE < myCamera.Position.x - 4 * SCALE)) {
				ants.insert(new Ant(x * SCALE, 0.12 * SCALE, z * SCALE * -1));
				break;
			}
		}
	}
}

int InitGL(GLvoid) // All Setup For OpenGL Goes Here
{
	myCamera = Camera();

	// 15
	myCamera.Position.x = 15 * SCALE;
	
	// 0.4
	myCamera.Position.y = 0.4 * SCALE;
	
	// 6.2
	myCamera.Position.z = -6.2 * SCALE;

	glShadeModel(GL_SMOOTH);                           // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);              // Black Background
	glClearDepth(1.0f);                                // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                           // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                            // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

	motherBoardWall = LoadTexture("media/mother_board_wall.bmp");
	motherBoardBottomTex = LoadTexture("media/mother_board_bottom.bmp");
	ramTex = LoadTexture("media/ram.bmp");
	gpuFront = LoadTexture("media/gpu_front.bmp");
	gpuBack = LoadTexture("media/gpu_back.bmp");
	cpuTex = LoadTexture("media/cpu.bmp");
	ssdTex = LoadTexture("media/ssd.bmp");
	ramTex2 = LoadTexture("media/basic.bmp");
	fanTex = LoadTexture("media/fan_tex.bmp");
	buttonTex = LoadTexture("media/button.bmp");
	initialize.InitOpenAL(); // initialize sound from OpenAl
	shootingSound = Sound("media/shot.wav");
	
	handleBorder();
	person = new Person();
	initAnts();
	
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffues);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_SHININESS, shin);

	return TRUE; // Initialization Went OK
}

void handleKeybordInput()
{
	// ==================================
	if (keys[VK_LEFT]) {
		myCamera.RotateY(0.3);
	}
	if (keys[VK_RIGHT]) {
		myCamera.RotateY(-0.3);
	}
	if (keys[VK_DOWN]) {
		myCamera.RotateX(-0.3);
	}
	if (keys[VK_UP]) {
		myCamera.RotateX(0.3);
	}
	if (keys['W'])
        myCamera.MoveForward(1);
    if (keys['S'])
        myCamera.MoveForward(-1);
    if (keys['A'])
        myCamera.MoveRight(-1);
    if (keys['D'])
        myCamera.MoveRight(1);
	if(keys[VK_SPACE] && canFire) {
		shootingSound.Play();
		shootingSoundIsPlaying = true;
		shootingSoundStartTime = time(0);
		canFire = false;
		// Shooting.
		bullets.insert(new Bullet(myCamera.Position.x, myCamera.Position.y, myCamera.Position.z, myCamera.View.x, myCamera.View.y, myCamera.View.z));
	}
	if(!keys[VK_SPACE]){
		canFire = true;
	}
}

void myDrawings() {
	Enviroment::drawSleepbutton(buttonTex);

	Enviroment::drawMotherBoard(motherBoardBottomTex, motherBoardWall);

	Enviroment::drawCPU(cpuTex);

	Enviroment::drawGPU(gpuFront, gpuBack);

	glPushMatrix();
	double i = -7.8, j = 17.2;
		while(i + 0.2 < -2.8) {
			Enviroment::cpuChips(i,j);
			i += 0.2;
			j += 0.2;
		}
	glPopMatrix();

	glPushMatrix();
	Enviroment::Capacitor(24,-8);
	Enviroment::Capacitor(24,-4);
	glPopMatrix();

	// Drawing SSDs
	// =======================================
	glPushMatrix();
	for(int i = 0; i < 4; i++) {
		Enviroment::drawSSD(ssdTex);
		glTranslated(3, .0, .0);
	}
	glPopMatrix();

	// Drawing pices RAMs
	// =======================================
	 glPushMatrix();
	
	for(int i = 0; i < 4; i++) {
		Enviroment::drawpices();
		glTranslated(0.8, .0, .0);
	}
	glPopMatrix();

	// Drawing RAMs
	// ======================================= 
	glPushMatrix();
	
	for(int i = 0; i < 4; i++) {
		Enviroment::drawRAM(ramTex);
		glTranslated(0.8, .0, .0);
	}
	glPopMatrix();
	
	// Drawing pices RAMs
	// =======================================
	glPushMatrix();
	for(int i = 0; i < 4; i++) {
		Enviroment::drawpices();
		glTranslated(0.8, .0, .0);
	}
	glPopMatrix();

	// Drawing drawRamEntrances RAMs
	// =======================================
	glPushMatrix();
	Enviroment::drawRamEntrances(ramTex2);
	glPopMatrix();
	//========================================

	
	// Drawing Fan
	// =======================================
	glPushMatrix();
	// Drawn at (5, 0, -5).
	glTranslated(5, 0, -5);
	glRotated(fanRotate, 0, 1, 0);

	Enviroment::drawFan(fanTex);
	fanRotate += 0.1;

	glPopMatrix();

	// Drawing Pins
	// =======================================
	glPushMatrix();
	for(int i = 0; i < 2; i++) {
		Enviroment::drawPin();
		glTranslated(2, .0, .0);
	}
	glPopMatrix();
	// Drawing CPU glass
	// =======================================
	glPushMatrix();
	glTranslated(1.5, .0, .0);
	Enviroment::drawCpuGlass();
	glPopMatrix();
	// Drawing RAM glass
	// =======================================
	glPushMatrix();
	glTranslated(1.5, 0, 0);
	Enviroment::drawRamGlass();
	glPopMatrix();
	// Drawing STORAGE glass
	// =======================================
	glPushMatrix();
	Enviroment::drawStorageGlass();
	glPopMatrix();
	// Drawing FAN glass
	// =======================================
	glPushMatrix();
	glTranslated(1.5, .0, .0);
	Enviroment::drawFanGlass();
	glPopMatrix();
}

int DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	handleKeybordInput();

	person->drawX();
	person->draw();

	myCamera.Render();

	if(ants.size() == 0) {
		initAnts();
	}

	if(shootingSoundIsPlaying && time(0) - shootingSoundStartTime == 2) {
		shootingSoundIsPlaying = false;
		shootingSound.Stop();
	}

	// An ant killed me.
	for(auto it : ants) {
		if((it)->z <= myCamera.Position.z + 0.5 * SCALE
			&& (it)->z >= myCamera.Position.z - 0.5 * SCALE
			&& (it)->x <= myCamera.Position.x + 0.5 * SCALE
			&& (it)->x >= myCamera.Position.x - 0.5 * SCALE) {
			exit(0);
		}
	}

	vector<set<Bullet*>::iterator> toDeleteBullets; 
	vector<set<Ant*>::iterator> toDeleteAnts; 

	for(set<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
		(*it)->move();
		(*it)->draw();
		if((*it)->x > 25 * SCALE || (*it)->x < 1 * SCALE
			|| (*it)->z < -25 * SCALE || (*it)->z > -1 * SCALE
			|| (*it)->y > 25 * SCALE || (*it)->y < 0
			|| !border[(int) ceil((*it)->x)][abs((int) ceil((*it)->z))]
			) {
			toDeleteBullets.push_back(it);
			continue;
		}
		if((*it)->x > 2240 && (*it)->x < 2380
		&& (*it)->z > -3500 && (*it)->z < -3430
		&& (*it)->y > 140 && (*it)->y < 210
		) {
			if(enableLight){
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				enableLight = !enableLight;
			}
			else{
				glDisable(GL_LIGHTING);
				enableLight = !enableLight;
			}
			toDeleteBullets.push_back(it);
			continue;
		}
		for(set<Ant*>::iterator it2 = ants.begin(); it2 != ants.end(); it2++) {
			if((*it)->y <= (*it2)->y + 0.3 * SCALE
				&& (*it)->y >= (*it2)->y - 0.3 * SCALE
				&& (*it)->z <= (*it2)->z + 0.3 * SCALE
				&& (*it)->z >= (*it2)->z - 0.3 * SCALE
				&& (*it)->x <= (*it2)->x + 0.3 * SCALE
				&& (*it)->x >= (*it2)->x - 0.3 * SCALE) {
				toDeleteAnts.push_back(it2);
				toDeleteBullets.push_back(it);
				break;
			}
		}
	}
	for(auto it : toDeleteBullets) {
		bullets.erase(it);
	}

	for(auto it : toDeleteAnts) {
		ants.erase(it);
	}

	for(set<Ant*>::iterator it = ants.begin(); it != ants.end(); it++) {
		(*it)->move(myCamera.Position.x, myCamera.Position.z);
		(*it)->draw();
	}

	glScaled(SCALE, SCALE, SCALE);

	myDrawings();
	
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd,     // Handle For This Window
						 UINT uMsg,     // Message For This Window
						 WPARAM wParam, // Additional Message Information
						 LPARAM lParam) // Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg) // Check For Windows Messages
	{
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE: // Watch For Window Activate Message
		{
			if (!HIWORD(wParam)) // Check Minimization State
			{
				active = TRUE; // Program Is Active
			}
			else
			{
				active = FALSE; // Program Is No Longer Active
			}

			return 0; // Return To The Message Loop
		}

	case WM_SYSCOMMAND: // Intercept System Commands
		{
			switch (wParam) // Check System Calls
			{
			case SC_SCREENSAVE:   // Screensaver Trying To Start?
			case SC_MONITORPOWER: // Monitor Trying To Enter Powersave?
				return 0;         // Prevent From Happening
			}
			break; // Exit
		}

	case WM_CLOSE: // Did We Receive A Close Message?
		{
			PostQuitMessage(0); // Send A Quit Message
			return 0;           // Jump Back
		}

	case WM_KEYDOWN: // Is A Key Being Held Down?
		{
			keys[wParam] = TRUE; // If So, Mark It As TRUE
			return 0;            // Jump Back
		}

	case WM_KEYUP: // Has A Key Been Released?
		{
			keys[wParam] = FALSE; // If So, Mark It As FALSE
			return 0;             // Jump Back
		}

	case WM_SIZE: // Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam), HIWORD(lParam)); // LoWord=Width, HiWord=Height
			return 0;                                      // Jump Back
		}
	case WM_MOUSEMOVE:
		{
			mouseX = (int)LOWORD(lParam);
			mouseY = (int)HIWORD(lParam);
			isLClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
			isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
			break;
		}
	case WM_LBUTTONUP:
		isLClicked = false;
		break;
	case WM_RBUTTONUP:
		isRClicked = false;
		break;
	case WM_LBUTTONDOWN:
		isLClicked = true;
		break;
	case WM_RBUTTONDOWN:
		isRClicked = true;
		break;
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

GLvoid KillGLWindow(GLvoid) // Properly Kill The Window
{
	if (fullscreen) // Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0); // If So Switch Back To The Desktop
		ShowCursor(TRUE);               // Show Mouse Pointer
	}

	if (hRC) // Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL)) // Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC)) // Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL; // Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC)) // Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL; // Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd)) // Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL; // Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance)) // Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL; // Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char *title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint PixelFormat;               // Holds The Results After Searching For A Match
	WNDCLASS wc;                      // Windows Class Structure
	DWORD dwExStyle;                  // Window Extended Style
	DWORD dwStyle;                    // Window Style
	RECT WindowRect;                  // Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;        // Set Left Value To 0
	WindowRect.right = (long)width;   // Set Right Value To Requested Width
	WindowRect.top = (long)0;         // Set Top Value To 0
	WindowRect.bottom = (long)height; // Set Bottom Value To Requested Height

	fullscreen = fullscreenflag; // Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);             // Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;             // WndProc Handles Messages
	wc.cbClsExtra = 0;                             // No Extra Window Data
	wc.cbWndExtra = 0;                             // No Extra Window Data
	wc.hInstance = hInstance;                      // Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);        // Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // Load The Arrow Pointer
	wc.hbrBackground = NULL;                       // No Background Required For GL
	wc.lpszMenuName = NULL;                        // We Don't Want A Menu
	wc.lpszClassName = "OpenGL";                   // Set The Class Name

	if (!RegisterClass(&wc)) // Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (fullscreen) // Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;                               // Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings)); // Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);     // Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;                   // Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;                 // Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;                   // Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE; // Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE; // Return FALSE
			}
		}
	}

	if (fullscreen) // Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW; // Window Extended Style
		dwStyle = WS_POPUP;          // Windows Style
		ShowCursor(FALSE);           // Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE; // Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;                  // Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,                          // Extended Style For The Window
		"OpenGL",                           // Class Name
		title,                              // Window Title
		dwStyle |                           // Defined Window Style
		WS_CLIPSIBLINGS |               // Required Window Style
		WS_CLIPCHILDREN,                // Required Window Style
		0, 0,                               // Window Position
		WindowRect.right - WindowRect.left, // Calculate Window Width
		WindowRect.bottom - WindowRect.top, // Calculate Window Height
		NULL,                               // No Parent Window
		NULL,                               // No Menu
		hInstance,                          // Instance
		NULL)))                             // Dont Pass Anything To WM_CREATE
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	static PIXELFORMATDESCRIPTOR pfd = // pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR), // Size Of This Pixel Format Descriptor
		1,                             // Version Number
		PFD_DRAW_TO_WINDOW |           // Format Must Support Window
		PFD_SUPPORT_OPENGL |       // Format Must Support OpenGL
		PFD_DOUBLEBUFFER,          // Must Support Double Buffering
		PFD_TYPE_RGBA,                 // Request An RGBA Format
		bits,                          // Select Our Color Depth
		0, 0, 0, 0, 0, 0,              // Color Bits Ignored
		0,                             // No Alpha Buffer
		0,                             // Shift Bit Ignored
		0,                             // No Accumulation Buffer
		0, 0, 0, 0,                    // Accumulation Bits Ignored
		16,                            // 16Bit Z-Buffer (Depth Buffer)
		0,                             // No Stencil Buffer
		0,                             // No Auxiliary Buffer
		PFD_MAIN_PLANE,                // Main Drawing Layer
		0,                             // Reserved
		0, 0, 0                        // Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd))) // Did We Get A Device Context?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd))) // Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd)) // Are We Able To Set The Pixel Format?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC))) // Are We Able To Get A Rendering Context?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC)) // Try To Activate The Rendering Context
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);    // Show The Window
	SetForegroundWindow(hWnd);    // Slightly Higher Priority
	SetFocus(hWnd);               // Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height); // Set Up Our Perspective GL Screen

	if (!InitGL()) // Initialize Our Newly Created GL Window
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	return TRUE; // Success
}

int WINAPI WinMain(HINSTANCE hInstance,     // Instance
				   HINSTANCE hPrevInstance, // Previous Instance
				   LPSTR lpCmdLine,         // Command Line Parameters
				   int nCmdShow)            // Window Show State
{
	MSG msg;           // Windows Message Structure
	BOOL done = FALSE; // Bool Variable To Exit Loop
	srand(time(0));

	// Ask The User Which Screen Mode They Prefer
	// if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE; // Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Ant Warrior", 640, 480, 16, fullscreen))
	{
		return 0; // Quit If Window Was Not Created
	}

	while (!done) // Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT) // Have We Received A Quit Message?
			{
				done = TRUE; // If So done=TRUE
			}
			else // If Not, Deal With Window Messages
			{
				TranslateMessage(&msg); // Translate The Message
				DispatchMessage(&msg);  // Dispatch The Message
			}
		}
		else // If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active) // Program Active?
			{
				if (keys[VK_ESCAPE]) // Was ESC Pressed?
				{
					done = TRUE; // ESC Signalled A Quit
				}
				else // Not Time To Quit, Update Screen
				{
					DrawGLScene();    // Draw The Scene
					SwapBuffers(hDC); // Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1]) // Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;      // If So Make Key FALSE
				KillGLWindow();           // Kill Our Current Window
				fullscreen = !fullscreen; // Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("Ant Warrior", 640, 480, 16, fullscreen))
				{
					return 0; // Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();      // Kill The Window
	return (msg.wParam); // Exit The Program
}

int main(HINSTANCE hInstance,     // Instance
				   HINSTANCE hPrevInstance, // Previous Instance
				   LPSTR lpCmdLine,         // Command Line Parameters
				   int nCmdShow) {
	return WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}