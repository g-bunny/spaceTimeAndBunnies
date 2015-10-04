#pragma once

#include "ofMain.h"
#include "Chapter7.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
        void draw();
    
    Chapter * chapter7;
    Chapter * chapter1;
//
		void keyPressed(int key);
		void keyReleased(int key);
    int currentChapter = 1;
    
    int widthThirds = 300;
    int widthHalves;
    int widthFull = 1125;
    int heightHalf = 300;
    int heightFull = 700;
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
};
