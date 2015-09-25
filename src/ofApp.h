#pragma once

#include "ofMain.h"
#include "Frame.hpp"
#include "Characters.hpp"
//#include "Timer.h"
#include "Item.h"
#include "cubeItems.h"
#define HOURLENGTH 4
#define MINLENGTH 5
#define SECLENGTH 6

class ofApp : public ofBaseApp{

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
    Frame * firstFrame;
    Frame * secondFrame;
    Frame * thirdFrame;
    Frame * fourthFrame;
    Frame * hourFrames[HOURLENGTH];
    Frame * minFrames[MINLENGTH];
    Frame * secFrames[SECLENGTH];
    Characters * one;
    Characters * zero;
    Timer * timer;
    ofSoundPlayer talk;
    ofSoundPlayer knock;
    ofSoundPlayer chimes;
    Item * door;
    Item * brickChimney;
    Item * clock;
    
    float hourIncrement = 0.5;
    float minIncrement = 1;
    float secIncrement = 6;
    
    bool downTheChimney = false;
    bool appropriateDist = false;
    
    bool showZero = false;

};
