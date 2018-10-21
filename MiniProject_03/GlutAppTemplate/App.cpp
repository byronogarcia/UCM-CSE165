#include "App.h"
#include "Rect.h"
#include "Game.h"
#include <math.h>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

    Rect* tileA1 = new Rect(-0.9, 0.9, 0.575, 0.575);
    Rect* tileA2 = new Rect(-0.275, 0.9, 0.55, 0.575); 
    Rect* tileA3 = new Rect(0.325, 0.9, 0.575, 0.575);

    Rect* tileB1 = new Rect(-0.9, 0.275, 0.575, 0.55);
    Rect* tileB2 = new Rect(-0.275, 0.275, 0.55, 0.55);
    Rect* tileB3 = new Rect(0.325, 0.275, 0.575, 0.55);

    Rect* tileC1 = new Rect(-0.9, -0.325, 0.575, 0.575);
    Rect* tileC2 = new Rect(-0.275, -0.325, 0.55, 0.575);
    Rect* tileC3 = new Rect(0.325, -0.325, 0.575, 0.575);

    Tiles.push_front(tileA1);
    Tiles.push_front(tileA2);
    Tiles.push_front(tileA3);
    Tiles.push_back(tileB1);
    Tiles.push_back(tileB2);
    Tiles.push_back(tileB3);
    Tiles.push_back(tileC1);
    Tiles.push_back(tileC2);
    Tiles.push_back(tileC3);

}

void App::draw() {
    //Rectangle variables for the gameboard (Looks like-> #)
    float RectX, RectY, Rectwidth, Rectheight;
    float TileX, TileY, Tilewidth, Tileheight;

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glColor3f(1.0, 1.0, 1.0);

    glLineWidth(100);

    glBegin(GL_LINES);

    glVertex2f(0.3, 0.9);   //Right Line
    glVertex2f(0.3, -0.9);  //Right Line

    glVertex2f(-0.3, 0.9);  //Left Line
    glVertex2f(-0.3, -0.9); //Left Line

    glVertex2f(0.9, 0.3);   //Top Line
    glVertex2f(-0.9, 0.3);  //Top Line

    glVertex2f(0.9, -0.3);  //Bottom Line
    glVertex2f(-0.9, -0.3); //Bottom Line

    glEnd();

    std::deque<Rect*>::size_type i;

  /*  for (i = 0; i != Board.size(); i++) {
        RectX = Board[i]->getX();
        RectY = Board[i]->getY();
        Rectwidth = Board[i]->getWidth();
        Rectheight = Board[i]->getHeight();

        //Color
        glColor3f(Board[i]->getR(), Board[i]->getG(), Board[i]->getB());

        //Rectangles
        glBegin(GL_POLYGON);
 
        glVertex2f(RectX, RectY);
        glVertex2f(RectX + Rectwidth, RectY);
        glVertex2f(RectX + Rectwidth, RectY - Rectheight);
        glVertex2f(RectX, RectY - Rectheight);

        glEnd();
    }*/

    for (i = 0; i != Tiles.size(); i + 2) {
        TileX = Tiles[i]->getX();
        TileY = Tiles[i]->getY();
        Tilewidth = Tiles[i]->getWidth();
        Tileheight = Tiles[i]->getHeight();

        //Color
        glColor3f(Tiles[i]->getR(), Tiles[i]->getG(), Tiles[i]->getB());
        //Rectangles
        glBegin(GL_LINES);

        glVertex2f(TileX, TileY);
        glVertex2f(TileX + Tilewidth, TileY - Tileheight);

        glVertex2f(TileX, TileY - Tileheight);
        glVertex2f(TileX + Tilewidth, TileY);


        glEnd();
    }

/*
    for (i = 1; i != Tiles.size(); i + 2) {
        TileX = Tiles[i]->getX();
        TileY = Tiles[i]->getY();
        Tilewidth = Tiles[i]->getWidth();
        //Tileheight = Tiles[i]->getHeight();

        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_LINE_LOOP);

        for(int i = 0; i <= 300; i++){
            float angle = 2 * M_PI * i / 300;
            float x = cos(angle);
            float y = sin(angle);

            glVertex2d(TileX + x, TileY + y);
        }

        glEnd();
    }
*/




/*    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    // Draw some points
    glBegin(GL_POINTS);
    
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    
    glEnd();
    
    // Draw a yellow cross
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINES);
    
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);
    
    glEnd();
    */

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    std::deque<Rect*>::size_type i;

    for (i = 0; i < Tiles.size(); i++) {
        if (Tiles[i]->contains(mx, my)) {
            if (Tiles[i]->getSelect()) {
                break;
            }

            else {
                //Setting the selected rectangle BLUE
                
                Tiles[i]->setR(0.0);
                Tiles[i]->setG(0.0);
                Tiles[i]->setB(1.0);
                Tiles[i]->setSelect(true);

                Tiles.push_front(Tiles[i]);
                Tiles.erase(Tiles.begin() + i + 1);
            }
        }

       /* else {
            //Setting Rectangle that is not selected as WHITE
            Tiles[i]->setR(1.0);
            Tiles[i]->setG(1.0);
            Tiles[i]->setB(1.0);
            Tiles[i]->setSelect(false);
        }*/
    }

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
