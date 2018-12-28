#ifndef Vec_h
#define Vec_h
//Vec is used in BALL.cpp line 51 by the way, if you can change this, please do
// I feel like using vec is a bit ratchet so if you can change it go for it
class Vec {
	float x, y;

public:
	//Default Constructor
	Vec () {
		x = 0.0;
		y = 0.0;
	}

	//Deconstructor
	~Vec() { }

	//Valued Constructor
	Vec (float x, float y) {
		this->x = x;
		this->y = y;
	}
	
	//Setters
	void setX (float x) {
		this->x = x;
	}
	void setY (float y) {
		this->y = y;
	}
	
	//Getters
	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
};

#endif /* Vec_h */