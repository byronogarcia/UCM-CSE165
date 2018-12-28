#ifndef GAME_H
#define GAME_H

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

#include "Ball.h"
#include "Platform.h"
#include "Level.h"
#include <vector>

class Game {
    Platform* plat;
    Ball* ball;

    //levels
    std::vector<Level> levels;

    int width;
    int height;
    float ballSpeed;
    float platSpeed;

    int level;
    bool resetMark;

    int lives;
    bool end, pause;
	GLuint lives_id;
	GLuint end_id;
	GLuint background_id;

	void resetLives();
	void setLivesDisp(const char*);
	void displayLives();

	void setEndDisp(const char*);
	void displayEnd();

	void setBackDisp(const char*);
	void displayBackground();

public:

	Game(int, int);

	Game(const char*, const char*, const char*, int, int);

	~Game();

	bool isWinner();	//Checks if all the blocks are broken

	void draw();

	void movePlatform(float);
	void moveBall();

	void collision();

	void reset();
	void resetGame();

	void functionKey(unsigned char);
	void pausing();

	void decLevel();
	void incLevel();
	bool newResetMark();

	void setBallSpeed(float);
	void setPlatSpeed(float);

	float getBallSpeed() const;
	float getPlatSpeed() const;
};

#endif
