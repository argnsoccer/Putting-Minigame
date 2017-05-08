#include "Barrier.h"


Barrier::Barrier()
{
}

Barrier::Barrier(int height, int width, ofVec2f pos):
	height(height), width(width), pos(pos){}

void Barrier::display()
{
	ofSetColor(255,0,0);
	ofRect(pos.x, pos.y, height, width);
	
}
