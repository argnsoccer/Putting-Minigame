#pragma once

#include "ofMain.h"
#include "Barrier.h"

class Circle
{
public:
	Circle();
	Circle(float radius, ofColor color, ofVec2f pos, ofVec2f spd);
	Circle(float radius, ofColor color, ofVec2f pos);
	void display();
	void move(Barrier * barriers);

	void setRadius(float radius);
	float getRadius();

	ofVec2f getPos();
	void setPos(ofVec2f pos);

	void setSpd(ofVec2f spd);
	ofVec2f getSpd();

	void setColor(ofColor color);
	ofColor getColor();


private:
	ofVec2f pos;
	ofVec2f spd;
	float radius;
	ofColor color;

};

inline void Circle::setRadius(float radius)
{
	this->radius = radius;
}

inline float Circle::getRadius()
{
	return radius;
}

inline void Circle::setPos(ofVec2f pos)
{
	this->pos = pos;
}

inline ofVec2f Circle::getPos()
{
	return pos;
}

inline void Circle::setSpd(ofVec2f spd)
{
	this->spd = spd;
}

inline ofVec2f Circle::getSpd()
{
	return spd;
}

inline void Circle::setColor(ofColor color)
{
	this->color = color;
}

inline ofColor Circle::getColor()
{
	return color;
}

