#pragma once

#include "ofMain.h"
#include "Frame.hpp"
#include "Characters.hpp"
#include "Timer.h"
#include "Item.h"
#include "cubeItems.h"

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
    Characters * one;
    Characters * zero;
    Timer * timer;
    ofSoundPlayer talk;
    Item * door;
    Item * brickChimney;
};
