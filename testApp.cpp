#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	mesh.setMode(OF_PRIMITIVE_LINES);
	ofSetBackgroundColor(0,255,0);
	ball = Circle(10, ofColor(255,255,255), ofVec2f((ofGetWidth()/2), ofGetHeight()-100), ofVec2f(0,0));
	hole = Circle(10, ofColor(0,0,0), ofVec2f(ofRandom(200, 700), ofRandom(20, 200)));
	barriers = new Barrier[5];
	sides = new ofVec2f[5];
	for(int i = 0; i < 5; i++)
	{
		barriers[i] = Barrier(200, 100, ofVec2f(ofRandom(100,ofGetWidth()-100), ofRandom(200,400)));
		sides[i] = ofVec2f(barriers[i].getPos().x, barriers[i].getPos().y);
	}
	

	applause.loadSound("C:/Users/Andre Gras/Music/app-5.mp3");

	cout << "Hello! Welcome to Simplified Putt Putt!" << endl;
	cout << "The goal of the game is to get the white ball to the black hole " << endl;
	cout << "Instructions: One mouse click inside the white ball will begin to draw your power line" << endl;
	cout << "then drag your mouse to where you want to draw your line. That line indicates power and direction" << endl;
	cout << "To reset your ball, press enter. To clear your power lines, press backspace" << endl;
	cout << "Good luck!" << endl;
	
}

//--------------------------------------------------------------
void testApp::update(){

	/*for(int i = 0; i < 5; i++)//bounds checking the barriers
	{
		/*if( ((ball.getPos().y + ball.getRadius()) >= sides[i].y) && ((ball.getPos().y - ball.getRadius()) <= sides[i].y) ||
			((ball.getPos().y - ball.getRadius()) <= (sides[i].y+barriers[i].getHeight()))){

			if((((ball.getPos().x + ball.getRadius()) >= sides[i].x) && ((ball.getPos().x - ball.getRadius()) <= sides[i].x + barriers[i].getWidth())) ){
		
			float dy = ball.getSpd().y * -1;
			ball.setSpd(ofVec2f(ball.getSpd().x, dy));
			}
		}
		else if(((ball.getPos().x + ball.getRadius()) >= sides[i].x) || ((ball.getPos().x - ball.getRadius()) <= (sides[i].x+barriers[i].getWidth()))){

			if((((ball.getPos().y + ball.getRadius()) >= sides[i].y) && ((ball.getPos().y - ball.getRadius()) <= (sides[i].y + barriers[i].getHeight()))) )
		{
			float dx = ball.getSpd().x * -1;
			ball.setSpd(ofVec2f(dx, ball.getSpd().y));
		}
		}
		float rad = ball.getRadius();
		if(((ball.getPos().x + rad) > sides[i].x) && (ball.getPos().x - rad) < (sides[i].x+barriers[i].getWidth()))
		{
			float dx = ball.getSpd().x * -1;
			ball.setSpd(ofVec2f(dx, ball.getSpd().y));

			if(((ball.getPos().y + rad) > sides[i].y) && ((ball.getPos().y - rad) < sides[i].y + barriers[i].getHeight()))
			{
				float dy = ball.getSpd().y * -1;
				ball.setSpd(ofVec2f(ball.getSpd().x,dy));
			}
		}
	}*/
	
	ball.move(barriers);
	//win case
	if((ball.getPos().x + ball.getRadius()) >= (hole.getPos().x - hole.getRadius()) && (ball.getPos().x - ball.getRadius()) <= (hole.getPos().x + hole.getRadius()) && (ball.getPos().y + ball.getRadius()) >= (hole.getPos().y - hole.getRadius()) && (ball.getPos().y - ball.getRadius()) <= (hole.getPos().y + hole.getRadius()))
	{
		applause.play();
		cout << " YOU WIN " << endl;
		exitApp();
		exit();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	mesh.draw();//draw the lines created using mesh
	ball.display();
	hole.display();
	for(int i = 0; i < 5; i++)
	{
		barriers[i].display();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == OF_KEY_BACKSPACE)
	{
		mesh.clear();//clear the mesh, deleting any lines created by the mouse 
	}
	else if(key == OF_KEY_RETURN)
	{
		ball = Circle(10, ofColor(255,255,255), ofVec2f((ofGetWidth()/2), (ofGetHeight()-100)), ofVec2f(0,0));//redeclare the ball to reset the ball's motion
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	//cout << "mouseDragged: " << x << ", " << y << " button: " << button << endl;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	float distance = ofDist((ofGetWidth()/2), (ofGetHeight()-100), x, y);

	if(distance < ball.getRadius())//makes sure the mouse click is inside the bounds of the circle before starting the line
	{
		point1x = x; point1y = y;
		point1 = ofVec3f(x,y,0);//first point of the line
		mesh.addVertex(point1);
	}
	else // makes sure the ball doesn't move if the line is not created starting in the ball
	{
		mesh.clear();
		ball = Circle(10, ofColor(255,255,255), ofVec2f((ofGetWidth()/2), (ofGetHeight()-100)), ofVec2f(0,0));
		powerx = 0;
		powery = 0;
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	point2 = ofVec3f(x,y,0);//on release, creates the second point of the line and adds it to the mesh, connecting the points
	mesh.addVertex(point2);

	point2x = x;
	point2y = y;

	powerx = -(point2x - point1x)/10;//creates the direction and speed of the ball based on the created line.
	powery = -(point2y - point1y)/10;// Divided by 10 to make the movement smoother and not as fast, as the line will be pixels long
	//and I wanted to keep the framerate at 60 
	
	cout << "powerx: " << powerx << endl;
	cout << "powery: " << powery << endl;

	if((powerx >= 1 || powerx <= 1) && (powery <= 1 || powery >=1))
	{
		ball.setSpd(ofVec2f(powerx, powery));
	}

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){//if the window is resized, recreates the game to better suit the window made
	ball = Circle(10, ofColor(255,255,255), ofVec2f((ofGetWidth()/2), (ofGetHeight()-100)), ofVec2f(0,0));
	hole = Circle(10, ofColor(0,0,0), ofVec2f(ofRandom(100, ofGetWidth()-100), ofRandom(20, 150)));
	for(int i = 0; i < 5; i++)
	{
		barriers[i] = Barrier(200, 100, ofVec2f(ofRandom(100,ofGetWidth()-100), ofRandom(200,400)));
	}

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
