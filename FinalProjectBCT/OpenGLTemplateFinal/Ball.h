#ifndef Ball_h
#define Ball_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <cmath>

class Ball{
protected:
    float x;
    float y;
    float radius;
    
    float r;
    float g;
    float b;
    
    float directionX;
    float directionY;
    float speed;

public:
    Ball(float=0.0f, float=0.0f, float=0.2f, float=1.0f, float=1.0f, float=1.0f, float=-1.0, float=0.0, float=0.5);
    
    float getX() const;
    float getY() const;
    float getRad() const;
    
    float getR() const;
    float getG() const;
    float getB() const;

    float getDx() const;
    float getDy() const;
    float getSpeed() const;
    
    void setX(float);
    void setY(float);
    void setRad(float);
    
    void setR(float);
    void setG(float);
    void setB(float);

    void setDx(float);
    void setDy(float);
    void setSpeed(float);
    
    bool contains(float, float) const;
    
    void redrawScene();

    float UpdateX();
    float UpdateY();
    
    virtual void draw() const;
    
    virtual ~Ball();
};



#endif