#ifndef BALL_H
#define BALL_H
// STL
#include <vector>
#include <cmath>
#include "Vec.h"
// Textures
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

class Ball {
    float x, y, radius;
    int resolution;

    GLuint ball_id;
    std::vector<Vec*> points;
    
    bool rising, moveLeft;  //Is ball moving
    float xinc, yinc;       //Speed of ball
public:

    Ball(const char*, const Vec&, float, int);

	~Ball();

    void reConfig();
	void print();

    bool contains(float, float) const;
    void jump();
    void stop();
    
    void setRadius(float);
    void setX(float);
    void setY(float);
    void setRising(bool);
    void setMoveLeft(bool);
    void setXinc(float);
    void setYinc(float);

  	float getRadius() const;
    float getX() const;
    float getY() const;
    bool getRising() const;
    bool getMoveLeft() const;
    float getXinc() const;
    float getYinc() const;
};

#endif