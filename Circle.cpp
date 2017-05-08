#include "Circle.h"
#include "ofMain.h"

Circle::Circle():
	radius(5), color(ofColor(255,255,255)), pos(ofVec2f(0,0)), spd(ofVec2f(0,0)){}

Circle::Circle(float radius, ofColor color, ofVec2f pos):
	radius(radius), color(color), pos(pos){}

Circle::Circle(float radius, ofColor color, ofVec2f pos, ofVec2f spd):
	radius(radius), color(color), pos(pos), spd(spd){}

void Circle::display()
{
	ofSetColor(color);
	ofCircle(pos.x, pos.y, radius);
}

void Circle::move(Barrier * barriers)
{	
	if(pos.x >= ofGetWidth()-radius){//code from class example particle 2 //bounds check the edges of the window
        spd.x *=-1;
    }
    
    else if(pos.x <= radius){
        spd.x *=-1;
    }

	else if(pos.y >= ofGetHeight()-radius){
		spd.y *=-1;
	}

	else if(pos.y <= radius){
		spd.y *=-1;
	}
	for(int i = 0; i < 5; i++)//bounds checking the barriers
	//most problems occur here, still not sure what the problems in the bounds checking are
	{
		if( ( (((pos.y + radius) >= barriers[i].getPos().y) && ((pos.y - radius) <= barriers[i].getPos().y)) ||
			(((pos.y - radius) <= (barriers[i].getPos().y+barriers[i].getHeight())) && ((pos.y + radius) >= (barriers[i].getPos().y + barriers[i].getHeight()))) ) &&
		   (((pos.x + radius) >= barriers[i].getPos().x) && ((pos.x - radius) <= barriers[i].getPos().x + barriers[i].getWidth())) )
		{
			spd.y*=-1;
		}
		else if( ( (((pos.x + radius) >= barriers[i].getPos().x) && ((pos.x - radius) <= barriers[i].getPos().x)) ||
			(((pos.x - radius) <= (barriers[i].getPos().x+barriers[i].getWidth())) && ((pos.x + radius) >= (barriers[i].getPos().x + barriers[i].getWidth()))) ) &&
		   (((pos.y + radius) >= barriers[i].getPos().y) && ((pos.y - radius) <= (barriers[i].getPos().y + barriers[i].getHeight()))) )
		{
			spd.x*=-1;
		}
	}
	pos += spd;
}




