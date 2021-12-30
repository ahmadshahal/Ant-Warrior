#define _CRT_SECURE_NO_DEPRECATE
#pragma once
#include <windows.h> // Header File For Windows
#include <gl/gl.h>   // Header File For The OpenGL32 Library
#include <gl/glu.h>  // Header File For The GLu32 Library
// #include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <vector>
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

vector<Ant*> ants;
vector<Bullet*> bullets;
int initialNumOfAnts = 15;

Person* person;

Camera myCamera;
int mouseX = 0, mouseY = 0;
bool isLClicked = 0, isRClicked = 0;

// ======================================================================================

double horizontalAngle = 90;
double verticalAngle = 0;
double R = 0.3;

// ======================================================================================
int motherBoardBottomTex, motherBoardWall;
int ramTex, desktopTex, gpuFront, gpuBack, cpuTex, ssdTex;
double fanRotate = 0;
bool shootingSoundIsPlaying = false;
time_t shootingSoundStartTime;

INIT initialize = INIT(); // Sound Initialize
Sound shootingSound;
Sound sound2;

GLUquadric *quadric = gluNewQuadric();

// ======================================================================================

// ======================================================================================

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

int InitGL(GLvoid) // All Setup For OpenGL Goes Here
{
	myCamera = Camera();

	// Before scalling will be => 120 / 8 = 15
	myCamera.Position.x = 120.0;
	// Before scalling will be => 3 / 8 = 0.375
	myCamera.Position.y = 3;
	// Before scalling will be => -16 / 8 = -2
	myCamera.Position.z = -16.0;

	glShadeModel(GL_SMOOTH);                           // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);              // Black Background
	glClearDepth(1.0f);                                // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                           // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                            // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

	motherBoardWall = LoadTexture("media/mother_board_wall.bmp");
	motherBoardBottomTex = LoadTexture("media/mother_board_bottom.bmp");
	ramTex = LoadTexture("media/ram.bmp");
	desktopTex = LoadTexture("media/windows-7.bmp");
	gpuFront = LoadTexture("media/gpu_front.bmp");
	gpuBack = LoadTexture("media/gpu_back.bmp");
	cpuTex = LoadTexture("media/cpu.bmp");
	ssdTex = LoadTexture("media/ssd.bmp");
	initialize.InitOpenAL(); // initialize sound from OpenAl
	shootingSound = Sound("media/shot.wav");
	sound2 = Sound("media/music.wav");

	handleBorder();

	person = new Person(myCamera.Position.x + 0.1, myCamera.Position.y - 0.1, myCamera.Position.z - 0.37);

	for(int i = 0; i < initialNumOfAnts; i++) {
		// TODO: While loop checking if the (x, z) aren't false.
		GLdouble x = 1 + (double)(rand()) / ((double)(RAND_MAX / (25 - (1))));
		GLdouble z = -25 + (double)(rand()) / ((double)(RAND_MAX / (-1 - (-25))));
		ants.push_back(new Ant(x, 0.12, z));
	}

	return TRUE; // Initialization Went OK
}

void handleMouseInput(int mouseX, int mouseY, bool isLClicked, bool isRClicked)
{
	if(isLClicked) {
		shootingSound.Play();
		shootingSoundIsPlaying = true;
		shootingSoundStartTime = time(0);
	}
	// myCamera.RotateY(-0.1 * ((mouseX - previousMouseX)));
	// myCamera.RotateX(-0.1 * ((mouseY - previousMouseY)));
	// previousMouseX = mouseX;
	// previousMouseY = mouseY;
}

void handleKeybordInput()
{
	// ==================================
	if (keys[VK_LEFT]) {
		myCamera.RotateY(0.2);
		horizontalAngle += 0.2;
		if(horizontalAngle >= 360) {
			horizontalAngle -= 360;
		}
	}
	else if (keys[VK_RIGHT]) {
		myCamera.RotateY(-0.2);
		horizontalAngle -= 0.2;
		if(horizontalAngle <= 0) {
			horizontalAngle = 360 + horizontalAngle;
		}
	}
	else if (keys[VK_DOWN]) {
		myCamera.RotateX(-0.2);
		verticalAngle -= 0.2;
		if(verticalAngle <= 0) {
			verticalAngle = 360 + verticalAngle;
		}
	}
	else if (keys[VK_UP]) {
		myCamera.RotateX(0.2);
		verticalAngle += 0.2;
		if(verticalAngle >= 360) {
			verticalAngle -= 360;
		}
	}
	// ==================================
	if (keys['Q'])
		myCamera.MoveUpward(0.03);
	if (keys['E'])
		myCamera.MoveUpward(-0.03);
	// ==================================
	int x = myCamera.Position.x;
	int z = abs(myCamera.Position.z);
	if (keys['W'] && border[x][z])
        myCamera.MoveForward(0.05);
    if (keys['S'] /*&& border[x][z]*/)
        myCamera.MoveForward(-0.05);
    if (keys['A'] && border[x][z])
        myCamera.MoveRight(-0.05);
    if (keys['D'] && border[x][z])
        myCamera.MoveRight(0.05);
	// ==================================
	if (keys['M'])
		sound2.Play();
	if(keys[VK_SPACE]) {
		bullets.push_back(new Bullet(myCamera.Position.x,
			myCamera.Position.y,
			myCamera.Position.z,
			myCamera.View.x,
			myCamera.View.y,
			myCamera.View.z));
	}
}

int DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	myCamera.Render();
	handleKeybordInput();

	handleMouseInput(mouseX, mouseY, isLClicked, isRClicked);

	// Stopping the shooting sound after 2 seconds.
	if(shootingSoundIsPlaying && time(0) - shootingSoundStartTime == 2) {
		shootingSoundIsPlaying = false;
		shootingSound.Stop();
	}

	double lookingY = sin(verticalAngle * PI / 180.0) * R;
	double R2 = cos(verticalAngle * PI / 180.0) * R;
	double lookingX = cos(horizontalAngle * PI / 180.0) * R2;
	double lookingZ = sin(horizontalAngle * PI / 180.0) * R2;

	Enviroment::drawX(
		myCamera.Position.x + lookingX,
		myCamera.Position.y + lookingY,
		(myCamera.Position.z) - lookingZ, horizontalAngle, verticalAngle);

	person->x = myCamera.Position.x + lookingX;
	person->y = myCamera.Position.y + lookingY;
	person->z = myCamera.Position.z - lookingZ;

	person->draw(horizontalAngle, verticalAngle);
	
	vector<vector<Bullet*>::iterator> toDeleteBullets; 

	for(vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
		(*it)->move();
		(*it)->draw();
		if((*it)->x > 25 || (*it)->x < 1
			|| (*it)->z < -25 || (*it)->z > -1
			|| (*it)->y > 30 || (*it)->y < 0) {
			// toDeleteBullets.push_back(it);
		}
	}
	for(auto it : toDeleteBullets) {
		bullets.erase(it);
	}

	// Making the world larger :)
	glScaled(8, 8, 8);

	for(int i = 0; i < ants.size(); i++) {
		ants[i]->draw();
	}

	Enviroment::drawMotherBoard(motherBoardBottomTex, motherBoardWall);

	Enviroment::drawCPU(cpuTex);

	Enviroment::drawGPU(gpuFront, gpuBack);

	Enviroment::drawMonitor(desktopTex);

	// Drawing SSDs
	// =======================================
	glPushMatrix();
	for(int i = 0; i < 4; i++) {
		Enviroment::drawSSD(ssdTex);
		glTranslated(3, .0, .0);
	}
	glPopMatrix();
	// Drawing STORAGE glass
	// =======================================
	glPushMatrix();
	Enviroment::drawStorageGlass();
	glPopMatrix();

	// Drawing RAMs
	// =======================================
	glPushMatrix();
	for(int i = 0; i < 4; i++) {
		Enviroment::drawRAM(ramTex);
		glTranslated(1.5, .0, .0);
	}
	glPopMatrix();
	// Drawing RAM glass
	// =======================================
	glPushMatrix();
	glTranslated(1.5, 0, 0);
	Enviroment::drawRamGlass();
	glPopMatrix();

	// Drawing Fan
	// =======================================
	glPushMatrix();
	// Drawn at (5, 0, -5).
	glTranslated(5, 0, -5);
	glRotated(fanRotate, 0, 1, 0);

	Enviroment::drawFan();
	fanRotate += 0.1;

	glPopMatrix();

	// Drawing CPU glass
	// =======================================
	glPushMatrix();
	glTranslated(1.5, .0, .0);
	Enviroment::drawCpuGlass();
	glPopMatrix();

	// Drawing Pins
	// =======================================
	glPushMatrix();
	for(int i = 0; i < 2; i++) {
		Enviroment::drawPin();
		glTranslated(2, .0, .0);
	}
	glPopMatrix();
	// Drawing FAN glass
	// =======================================
	glPushMatrix();
	glTranslated(1.5, .0, .0);
	Enviroment::drawFanGlass();
	glPopMatrix();

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