#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include"Square.h"
#include "TicTacToe.h"
#include<string>
#include<vector>
#include<cmath>
using std::vector;
using std::string;

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    //add new
    vector<Square*> grid; //i could use deque
    TicTacToe game;
    void MenuScreen();
    void GameInterface();
    void EndScreen();
public:
    // Constructor, to initialize stat
    App(const char* label, int x, int y, int w, int h);

    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    //add new
    void gridInit();
    void standby();

};

#endif
