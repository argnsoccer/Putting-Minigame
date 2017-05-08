#pragma once
#include "ofMain.h"

class Barrier
{
public:
	Barrier();
	Barrier(int height, int width, ofVec2f pos);
	void display();

	ofVec2f getPos();
	void setPos(ofVec2f pos);
		
	void setHeight(int height);
	int getHeight();

	void setWidth(int width);
	int getWidth();

private:
	int height;
	int width;
	ofVec2f pos;
};


inline void Barrier::setHeight(int height)
{
	this->height = height;
}

inline int Barrier::getHeight()
{
	return height;
}

inline void Barrier::setPos(ofVec2f pos)
{
	this->pos = pos;
}

inline ofVec2f Barrier::getPos()
{
	return pos;
}

inline void Barrier::setWidth(int width)
{
	this->width = width;
}

inline int Barrier::getWidth()
{
	return width;
}


