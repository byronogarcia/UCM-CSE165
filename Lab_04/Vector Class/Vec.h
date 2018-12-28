#ifndef Vec_h
#define Vec_h

#include <iostream>
#include <vector>

using namespace std;

class Vec {

	float x, y;

public:	
	Vec() {

		x = 0;
		y = 0;

	}

	Vec(float x, float y) {

		this->x = x;
		this->y = y;

	}

	float getX() const {

		return x;

	}

	float getY() const {

		return y;

	}

	void add(Vec &point) {

		this->x += point.x;
		this->y += point.y;

	}

	void print() {

		cout << "(" << x << ", " << y << ")" << endl;

	}

};


#endif