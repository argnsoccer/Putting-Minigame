#pragma once

#include "ofMain.h"
#include "Circle.h"
#include "Barrier.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofSoundPlayer applause;
		ofVec2f * sides; 
		Circle ball;
		Circle hole;
		Barrier * barriers;
		int point1x;
		int point1y;
		int point2x;
		int point2y;
		float powerx;
		float powery;
		ofVec3f point1;
		ofVec3f point2;
		ofMesh mesh;

		
};
