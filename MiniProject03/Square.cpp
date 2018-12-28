 #include"Square.h"

Square::Square() = default;

Square::Square(float x, float y) {
	xcoord = x;
	ycoord = y;
	//always the same
	length = 0.666f;
	width  = 0.666f;
	//this is the center of the box
	xcent = xcoord + (width / 2);
	ycent = ycoord - (length /2);
	//what is the shape?
	object = Undetermined;
	//black
	red   = 0.0f;
	green = 0.0f;
	blue  = 0.0f;
}

void Square::setShape(shape object) {
	this->object = object;
}

void Square::setColors(float r, float g, float b) {
	red   = r;
	green = g;
	blue  = b;
}

//Getters
float Square::getX() {
  return xcoord;
}
float Square::getY() {
  return ycoord;
}
float Square::getXcent() {
  return xcent;
}
float Square::getYcent() {
  return ycent;
}
shape Square::getShapeType() {
  return object;
}
float Square::getRed() {
  return red;
}
float Square::getGreen() {
  return green;
}
float Square::getBlue() {
  return blue;
}

//bool contains; the one we did previously on the lab
bool Square :: contains(float mx, float my)
{
	if((mx > xcoord) && (mx < (xcoord + width)))
	{
		if((my < ycoord) && (my > (ycoord - length)))
			return true;
	}

	return false;
}