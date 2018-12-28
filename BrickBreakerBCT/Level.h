#ifndef Level_h
#define Level_h

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

#include "Brick.h"
#include <vector>

class Level {
    // Initialize level from tile data
    void      init(std::vector<std::vector<int> > tileData, float levelWidth, float levelHeight);
public:
    // Level state
    std::vector<Brick> bricks;
    // Constructor
    Level() { }
    // Loads level from file
    void load(const char *file, float levelWidth, float levelHeight);
    // Render level
    void draw();
    // Check if the level is completed (all non-solid tiles are destroyed)
    bool isCompleted();
};

#endif
