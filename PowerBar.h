#pragma once
#include "ofMain.h"

class PowerBar
{
public:
	PowerBar();
	PowerBar(int length);

	void display();
	void setPowerRating();

	void setLength(int length);
	int getLength();

private:
	int length;


};

inline void PowerBar::setLength(int length)
{
	this->length = length;
}

inline int PowerBar::getLength()
{
	return length;
}

