#ifndef Rect_h
#define Rect_h

//#include <iostream>

//using namespace std;

class Rect {
public:

	float x, y, width, height;
	float r, g, b; //colors
	bool select;

	Rect() {
		x = y = width = height = 0;
	}

	Rect(float x, float y, float width, float height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;

		r = 1.0;
		g = 1.0;
		b = 1.0;
	}


	//Getters

	float getX() const {
		return x;
	}

	float getY() const {
		return y;
	}

	float getWidth() const {
		return width;
	}

	float getHeight() const {
		return height;
	}

	float getR() const {
		return r;
	}

	float getG() const {
		return g;
	}

	float getB() const {
		return b;
	}

	float getSelect() const {
		return select;
	}

	//Setters

	float setX(float x) {
		this->x = x;
	}

	float setY(float y) {
		this->y = y;
	}

	float setWidth(float width) {
		this->width = width;
	}

	float setHeight(float height) {
		this->height = height;
	}

	float setR(float r) {
		this->r = r;
		return r;
	}

	float setG(float g) {
		this->g = g;
		return g;
	}

	float setB(float b) {
		this->b = b;
		return b;
	}

	float setSelect(bool select) {
		this->select = select;
		//return select;
	}


	bool contains(float x, float y) {
		if(x >= this->x) {
			if(x <= this->x + width) {
				if(y <= this->y) {
					if(y >= this->y - height) {
						return true;
					}
				}
			}		
		}
		return false;
	}

};
#endif
