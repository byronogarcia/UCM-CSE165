#ifndef Rect_h
#define Rect_h
#include <iostream>

using namespace std; 

class Vec{
    public:
    
    float x, y;
    
    Vec() {
        x = 0;
        y = 0;
    }
    
    Vec(float h, float k) {
        x = h; y = k;
    }
};

class Rect{
    float Rx, Ry;
    float Rw, Rh;
    
    public:
    
    Rect() {
        Rx = Ry = Rw = Rh = 0;
    }
    
    Rect(float Rx, float Ry, float Rw, float Rh) {
        this->Rx = Rx; this->Ry = Ry; this->Rw = Rw; this->Rh = Rh;
    }
    
    bool contains(Vec v) {
        if(Rx <= v.x && (Rx + Rw) >= v.x && Ry >= v.y && (Ry - Rh) <= v.y) {
            return true;
        }
        else {
            return false;
        }
    }
};
#endif
