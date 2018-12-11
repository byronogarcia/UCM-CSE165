#include "Ball.h"

Ball::Ball(float x, float y, float radius, float r, float g, float b, float directionX, float directionY, float speed): x(x), y(y), radius(radius), r(r), g(g), b(b), directionX(directionX), directionY(directionY), speed(speed){
    
}

float Ball::getX() const {
    return x;
}

float Ball::getY() const {
    return y;
}

float Ball::getRad() const {
    return radius;
}

float Ball::getR() const {
    return r;
}

float Ball::getG() const {
    return g;
}

float Ball::getB() const {
    return b;
}

float Ball::getDx() const {
    return directionX;
}

float Ball::getDy() const {
    return directionY;
}

float Ball::getSpeed() const {
    return speed;
}

void Ball::setX(float x) {
    this->x = x;
}

void Ball::setY(float y) {
    this->y = y;
}

void Ball::setRad(float radius) {
    this->radius = radius;
}

void Ball::setR(float r) {
    this->r = r;
}

void Ball::setG(float g) {
    this->g = g;
}

void Ball::setB(float b) {
    this->b = b;
}

void Ball::setDx(float directionX) {
    this->directionX = directionX;
}

void Ball::setDy(float directionY) {
    this->directionY = directionY;
}

void Ball::setSpeed(float speed) {
    this->speed = speed;
}
 
void Ball::UpdateX(x) {
    x += directionX * speed;
    return x;
}

void Ball::UpdateY(x) {
    y += directionY * speed;
    return y;
}

/*bool Ball::contains(float px, float py) const {
    return px >= x && px <= x + w && py <= y && py >= y - h;
}*/

void Ball::draw() const {
    glColor3f(r, g, b);
    int vertice = 1000; //smoother
    float rad   = 0.17f;
    float fullCircle = M_PI * 2;
   /* 
    glBegin(GL_POLYGON);
    
    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);
    
    glEnd();*/

    while(true) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(getX(), getY());

        for(int j = 0; j <= vertice; j++) {
            glVertex2f(getX()+rad*cosf(j*fullCircle/vertice), getY()+rad*sinf(j*fullCircle/vertice));
        }
        glEnd();

        UpdateX();
        UpdateY();
    }
    //draw();
   /* redraw();*/
}


void Ball::redrawScene(){
    glutPostRedisplay();
}

Ball::~Ball(){
    
}
