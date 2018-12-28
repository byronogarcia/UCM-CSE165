#include "Platform.h"

Platform::Platform(const char* platPic, float x=-0.125, float y=-0.81, float h=0.05, float w=0.25) {
//Soil textures and clearing the background for the textures
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    plat_id = SOIL_load_OGL_texture (
    	platPic,
    	SOIL_LOAD_AUTO,
    	SOIL_CREATE_NEW_ID,
     	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	this->x = x;
	this->y = y;
	this->h = h;
	this->w = w;
}
//destructor
Platform::~Platform() {}

//contains function provided
bool Platform::contains(float mx, float my) const {
	return mx >= x && mx <= x + w && my <= y && my >= y - h;
}

//binds the platform
void Platform::print() {

    glBindTexture( GL_TEXTURE_2D, plat_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(x, y - h);
    
    glTexCoord2f(0, 1);
    glVertex2f(x, y);
    
    glTexCoord2f(1, 1);
    glVertex2f(x + w, y);
    
    glTexCoord2f(1, 0);
    glVertex2f(x + w, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

//moving the platform an increment of m when moved left or right
//it has to be less than 1.0 or greater than negative 1.0 to not go beyond the screen boundaries
void Platform::move(float m) {
	//Checks boundaries for plat then moves m distance
	if ((x + m + w) <= 1.0 && (x + m) >= -1.0)
		x += m;
}
//Setters and Getters

void Platform::setX(int x) {
	this->x = x;
}
void Platform::setY(int y) {
	this->y = y;
}
void Platform::setH(int h) {
	this->h = h;
}
void Platform::setW(int w) {
	this->w = w;
}

float Platform::getX() const {
	return x;
}
float Platform::getY() const {
	return y;
}
float Platform::getH() const {
	return h;
}
float Platform::getW() const {
	return w;
}