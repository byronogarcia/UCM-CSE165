#include "Brick.h"
#include <algorithm>

Brick::Brick(const char* brick_id, float x, float y, float w, float h, float r, float g, float b){
//AGAIN BINDING TEXTURE

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->r = r;
    this->g = g;
    this->b = b;
    //this->count = count;

    this->brick_id = SOIL_load_OGL_texture (
        brick_id,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    solid = destroyed = false;

}

//EDITED contains fucntion provided
//Make sure this all looks good, if not edit
//sometimes collsion detection doesn't always work

bool Brick::contains(float mx, float my, float r, float &closestX, float &closestY){
    closestX = clamp(mx, x, x + w);
    closestY = clamp(my, y - h, y);
    // Calculate the distance between the circle's center and this closest point
    float distanceX = mx - closestX;
    float distanceY = my - closestY;
    // If the distance is less than the circle's radius, an intersection occurs
    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    //std::cout << (distanceSquared < (r * r));
    return distanceSquared < (r * r);
}

//finding the max(min, min(max, val))
//clamp explained in contains function
float Brick::clamp(float val, float min, float max) {
    return std::max(min, std::min(max, val));
}

//draw with texture
void Brick::draw(){
    
    glBindTexture( GL_TEXTURE_2D, brick_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(r, g, b, 1);
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

//Some getters and setters

void Brick::setBrick_id(GLuint){}
void Brick::setSolid(bool boo){solid = boo;}
void Brick::setDestroyed(bool boo){destroyed = boo;}

float Brick::getX() const {
    return x;
}

float Brick::getY() const {
    return y;
}
float Brick::getH() const {
    return h;
}
float Brick::getW() const {
    return w;
}

bool Brick::isSolid() const {
    return solid;
}
bool Brick::isDestroyed() const { 
    return destroyed;
}

/*float Brick::count() const {
    return count;
}*/

//TRIED TO MAKE IT WORK WITH THIS BUT DIDN'T WORK

// bool Brick::contains(float mx, float my) const {
//     return mx >= x && mx <= x + w && my <= y && my >= y - h;
// }
