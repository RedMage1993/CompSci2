//****************************************************************************
// Name:	Fritz Ammon
// Assignment:	01
// Section:	1002
//
// Program:	This program will display a pentagon using OpenGL APIs.
//		It does not expect any input, however it may be terminated with
//		the Escape, Q, q, X, and x keys. It calculcates POINTS_TO_PLOT
//		points that make up the pentagon and draws it.

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <GL/glut.h>

#ifdef _WIN32
	#include <GL/gl.h>			// Use GL/gl.h shipped with Visual Studio
#else
	#include <GL/freeglut.h>	// or GL/freeglut.h in Ubuntu
#endif

using namespace std;

int main (int argc, char *argv[]);
int random(int min, int max);
void displayPentagons();
void openGLinit(int argc, char *argv[]);
void keyHandler(unsigned char key, int x, int y);

typedef unsigned int uint;

struct POINT	// Because nobody likes Windows
{
	GLdouble x;
	GLdouble y;
};

const uint POINTS_TO_PLOT = 250000;	//  The number of points to be plotted

//****************************************************************************
//	Main program for the OpenGL Fern

int main (int argc, char *argv[])
{
	cout << "CS 202 Assignment 01\nDurers Pentagon Program\n";

	//  Seed the random number generator
	srand(static_cast<uint> (time(reinterpret_cast<time_t*> (NULL))));

	//  Perform OpenGL initialization
	openGLinit (argc, argv);

	//  Set up key handler for an exit key
	glutKeyboardFunc (keyHandler);

	//  Initiate main loop
	glutMainLoop ();

	return 0;
}

//****************************************************************************
// Generate a random integer between min and max (inclusive).

int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}

//****************************************************************************
//  Generate the pentagon output via plotting (x,y) points.

//  Basic flow:
//	generate coordinates for point (per algorithm)
//	set color
//	plot point

//  To set a color, use glColor3ub(r, g, b) library function.
//	example: for green:
//		glColor3ub(0, 255, 0);

//  To plot a point, use glVertex2d(xCoord, yCoord) library function.
//	example:
//		glVertex2d(x,y);
//	note: x and/or y values out of range are ignored.

//  Color mapping (for example)
//	color for case 1 r=0, g=255, b=0
//	color for case 2 r=255, g=0, b=0
//	color for case 3 r=0, g=0, b=255
//	color for case 4 r=255, g=255, b=0
//	color for case 5 r=0, g=255, b=255
//	color for case 6 r=255, g=255, b=255

//	Note, once the program is working and submitted, if desired, 
//	you can adjust the color mapping.

void displayPentagons ( )
{
	// declarations...
	//	must declare variables
	POINT pt;

	//  Initialize the POINT structure
	memset(&pt, 0.0, sizeof(pt));

	//  Clear the window, set-up for point plotting
	glClear (GL_COLOR_BUFFER_BIT);
	glBegin (GL_POINTS);

	//  Compute and plot the points.
	//	your code goes here...

	for (uint point = 0; point < POINTS_TO_PLOT; point++)
	{
		switch (random(1, 6))
		{
		case 1:
			pt.x *= 0.382;
			pt.y *= 0.382;

			glColor3ub(0, 255, 0);
			break;

		case 2:
			pt.x = 0.382 * pt.x + 0.618;
			pt.y *= 0.382;

			glColor3ub(255, 0, 0);
			break;

		case 3:
			pt.x = 0.382 * pt.x + 0.809;
			pt.y = 0.382 * pt.y + 0.588;

			glColor3ub(0, 0, 255);
			break;

		case 4:
			pt.x = 0.382 * pt.x + 0.309;
			pt.y = 0.382 * pt.y + 0.951;

			glColor3ub(255, 255, 0);
			break;

		case 5:
			pt.x = 0.382 * pt.x - 0.191;
			pt.y = 0.382 * pt.y + 0.588;

			glColor3ub(0, 255, 255);
			break;

		case 6:
			pt.x = -0.382 * pt.x + 0.691;
			pt.y = -0.382 * pt.y + 0.951;

			glColor3ub(255, 255, 255);
			break;
		}

		glVertex2d(pt.x, pt.y);
	}

	//  Clear all buffers.
	glEnd ();
	glFlush ( );

	return;
}

//****************************************************************************
//  Keyboard input handler
//		Exit for Q/q/X/x/ESC keys

void keyHandler(unsigned char key, int x, int y)
{
	switch (key) {
		case 27:			// ESCAPE key
		case 'q':			// Q key
		case 'Q':			// q key
		case 'x':			// x key
		case 'X':			// X key
			exit (0);
			break;
	}

	return;
}


//****************************************************************************
//	Perform bnasic OpenGL initialization.
//		Custom for 2D drawing

void openGLinit (int argc, char *argv[])
{
//	Basic OpenGL initialization calls

	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (700, 600);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Durer Fractal Pentagons");

//	Set-up user-function (to be automatically called)
	glutDisplayFunc (displayPentagons);

//	Set the background to white.
	glClearColor (0.0, 0.0, 0.0, 0.0);		// black

//	Set up a viewing window:
//		2D picture
//		note, origin at the lower left
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (-0.5, 1.5, -0.1, 1.65);
	glMatrixMode (GL_MODELVIEW);

	return;
}
