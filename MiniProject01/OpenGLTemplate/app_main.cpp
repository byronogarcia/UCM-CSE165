#include <iostream>
#include <math.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;

// Store the width and height of the window
int width = 640, height = 640;

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw stuff here
	glLineWidth(100);

	// x, y variables to make semi circles in B, R, and O
	float lowBx1;
	float lowBy1;
	float lowBx2 = -0.9;
	float lowBy2 = -0.375;

	float highBx1;
	float highBy1;
	float highBx2 = -0.9;
	float highBy2 = 0.375;

	float Rx1;
	float Ry1;
	float Rx2 = -0.25;
	float Ry2 = 0.375;

	float Ox1;
	float Oy1;
	float Ox2 = 0.2125;
	float Oy2 = 0.0;

	
	//LETTER B ----------------------------------------------

	glColor3f(0.0, 1.0, 0.0); //Green

	glBegin(GL_LINES);

	glVertex2f(-0.9, -0.75);
	glVertex2f(-0.9, 0.75);

	glEnd();

	glBegin(GL_LINE_LOOP);

	for (int i = 75; i < 126; i++) {

		float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle

		float lowBx1 = 0.175 * cosf(theta); //calculate the x component
		float lowBy1 = 0.375 * sinf(theta); //calculate the y component

		glVertex2f(lowBx1 + lowBx2, lowBy1 + lowBy2); //output vertex

	}

	for (int i = 75; i < 126; i++) {
		
		float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle

		float highBx1 = 0.175 * cosf(theta); //calculate the x component
		float highBy1 = 0.375 * sinf(theta); //calculate the y component

		glVertex2f(highBx1 + highBx2, highBy1 + highBy2); //output vertex

	}

	glEnd();

	//LETTER Y ----------------------------------------------

	glColor3f(1.0, 0.0, 0.0); //Red

	glBegin(GL_LINES);
	// The Y arms on top
	glVertex2f(-0.6, 0.75);
	glVertex2f(-0.475, 0.1);

	glVertex2f(-0.475, 0.1);
	glVertex2f(-0.35, 0.75);

	// Y line down the middle
	glVertex2f(-0.475, 0.1);
	glVertex2f(-0.475, -0.75);

	//LETTER R ----------------------------------------------

	glColor3f(0.0, 0.0, 1.0); // Blue

	// R main line on back
	glVertex2f(-0.25, 0.75);
	glVertex2f(-0.25, -0.75);

	glEnd();

	glBegin(GL_LINE_LOOP);

	// R head
	for (int i = 75; i < 126; i++) {

		float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle

		float Rx1 = 0.175 * cosf(theta); //calculate the x component
		float Ry1 = 0.375 * sinf(theta); //calculate the y component

		glVertex2f(Rx1 + Rx2, Ry1 + Ry2); //output vertex

	}

	glEnd();

	glBegin(GL_LINES);

	// R Leg
	glVertex2f(-0.25, 0.0);
	glVertex2f(-0.0, -0.75);
	
	glEnd();

	//LETTER O ----------------------------------------------

	glColor3f(0.5, 0.0, 0.5); //Purple

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 100; i++) {

		float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle

		float Ox1 = 0.175 * cosf(theta); //calculate the x component
		float Oy1 = 0.75 * sinf(theta); //calculate the y component

		glVertex2f(Ox1 + Ox2, Oy1 + Oy2); //output vertex

	}

	glEnd();

	//LETTER N ----------------------------------------------

	glBegin(GL_LINES);

	glColor3f(1.0, 1.0, 0.0); // Yellow

	// N left line
	glVertex2f(0.5, 0.75);
	glVertex2f(0.5, -0.75);

	// N diagonal
	glVertex2f(0.5, 0.75);
	glVertex2f(0.85, -0.75);

	// N right line
	glVertex2f(0.85, -0.75);
	glVertex2f(0.85, 0.75);

	glEnd();

	
	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}


//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);



	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments: 	
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {

	// Again, we redraw the scene
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments: 	
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {


	// After all the state changes, redraw the scene
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);

	// Start the main loop
	glutMainLoop();
}