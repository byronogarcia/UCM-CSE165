#include "App.h"

static App* singleton;

void movePlat(int value) {

    if (singleton->moving) {
        singleton->newGame->moveBall();
    }
    
    if (singleton->left) {
        singleton->newGame->movePlatform(-1 * singleton->newGame->getPlatSpeed());
    }

    if (singleton->right) {
       singleton->newGame->movePlatform(singleton->newGame->getPlatSpeed());
    }

    if (singleton->left || singleton->right || singleton->moving) {
        singleton->redraw();
        glutTimerFunc(32, movePlat, value);
    }
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h) {
    // Initialize state variables
    singleton = this;
    mx = 0.0;
    my = 0.0;

    left = right = false;   //platform movement
    moving = false;         //ball movement

//OUR GAME STARTING UP
    newGame = new Game(w, h);

}

void App::draw() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    

    newGame->draw();


    glFlush();
    glutSwapBuffers();
}

void App::specialKeyPress(int key) {
    if (key == 100) //Move left
        left = true;
    if (key == 102) //Move right
        right = true;

   // movePlat(0.8);
}

void App::specialKeyUp(int key) {
    //Stops moving the platform
    if (key == 100)
        left = false;
    if (key == 102)
        right = false;
}

void App::idle() {
    newGame->collision();
}

void App::keyPress(unsigned char key) {
    if (key == 27) { //Esc Key
        delete newGame;
        exit(0);
    }

    newGame->functionKey(key);

    if (key == ' '){ //Space
        moving = true;
        if (newGame->newResetMark())
            movePlat(1);
    }
}
