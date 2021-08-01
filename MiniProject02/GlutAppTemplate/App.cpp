#include "App.h"
#include "Rect.h"
//#include <deque>
//#include <iostream>

using namespace std;

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables
	mx = 0.0;
	my = 0.0;

	

	Rect* rect1 = new Rect(0.5, 0.8, 0.2, 0.7);
	//Rect* rect1 = new Rect(-0.7, 0.8, 0.1, 0.7);
	Rect* rect2 = new Rect(-0.45, 0.8, 0.1, 0.7);

	//Rect* rect2 = new Rect(-0.7, 0.8, 0.1, 0.7);
	//Rect* rect3 = new Rect(-0.45, 0.8, 0.1, 0.7);

	Rect* rect4 = new Rect(-0.5, -0.8, 0.2, 0.7);

	List.push_front(rect1);
	List.push_front(rect2);
	//List.push_front(rect3);
	//List.push_front(rect4);

}

void App::draw() {

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// Draw some rectangles
	float x, y, width, height;

	std::deque<Rect *>::size_type i;

	for (i = 0; i != List.size(); i++) {
		x = List[i]->getX();
		y = List[i]->getY();
		width = List[i]->getWidth();
		height = List[i]->getHeight();

		//Color
		glColor3f(List[i]->getR(), List[i]->getG(), List[i]->getB());

		//Rectangles
		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y - height);
		glVertex2f(x, y - height);

		glEnd();
	}

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

void App::mouseDown(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	//Check for mouse click
	std::deque<Rect *>::size_type i;

	for (i = 0; i < List.size(); i++) {
		if (List[i]->contains(mx, my)) {
			if (List[i]->getSelect()) {
				break;
			}

			else {
				//Setting the selected rectangle BLUE
				List[i]->setR(0.0);
				List[i]->setG(0.0);
				List[i]->setB(1.0);
				List[i]->setSelect(true);

				List.push_front(List[i]);
				List.erase(List.begin() + i + 1);
			}
		}

		else {
			//Setting Rectangle that is not selected as WHITE
			List[i]->setR(1.0);
			List[i]->setG(1.0);
			List[i]->setB(1.0);
			List[i]->setSelect(false);
		}
	}

	redraw();

}

void App::mouseDrag(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::keyPress(unsigned char key) {
	if (key == 27) {
		// Exit the app when Esc key is pressed
		exit(0);
	}
}
