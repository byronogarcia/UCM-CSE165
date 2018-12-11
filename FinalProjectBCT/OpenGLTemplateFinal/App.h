#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Ball.h"


class App: public GlutApp {
    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;

    Ball* simpleball;
    
    AnimatedRect* RedBrick;
    AnimatedRect* RedReturnPiece;
    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
