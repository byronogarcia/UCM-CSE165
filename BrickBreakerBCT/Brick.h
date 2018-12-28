#ifndef BRICK_H
#define BRICK_H

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class Brick {
    float x;
    float y;
    float h;
    float w;

	float r;
	float g;
	float b;

	bool solid;
	bool destroyed;

	//float count;
	
    GLuint brick_id;
public:
	Brick(const char*, float, float, float, float, float, float, float);

	bool contains(float, float, float, float&, float&);
	float clamp(float, float, float);

	void draw();
	void setBrick_id(GLuint);
	void setSolid(bool);
	void setDestroyed(bool);

	float getX() const;
	float getY() const;
	float getH() const;
	float getW() const;

	bool isSolid() const;
	bool isDestroyed() const;

	// float count() const;
	//bool contains(float, float) const;

};

#endif
