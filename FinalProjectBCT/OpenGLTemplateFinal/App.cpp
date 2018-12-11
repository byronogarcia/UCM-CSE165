#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
    //explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    
    //fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);

    //RedBrick = new AnimatedRect("RedBrick.bmp", 5, 5, 10, -0.75, 0.8, 0.5, 0.5);
    //RedReturnPiece = new AnimatedRect("RedReturnPiece.bmp", 5, 5, 10, -0.5, 0.0, 0.5, 0.5);

    simpleball = new Ball(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.5f);
}

void App::draw() {
    //explosion->draw(0.15);
    //fastExplosion->draw(0.15);

    //RedBrick->draw(0.15);
    //RedReturnPiece->draw(0.15);

    simpleball->draw();

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
        //RedBrick->playOnce();
        //RedReturnPiece->playOnce();
        //fastExplosion->playOnce();
        //explosion->playOnce();
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    //delete RedBrick;
    //delete RedReturnPiece;
    //delete explosion;
    //delete fastExplosion;

    delete simpleball;
}
