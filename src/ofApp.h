#pragma once

#include "ofMain.h"
#include "Chapter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
        void draw();
        void keyPressed(int key);
        void keyReleased(int key);

    Chapter * chapter1;
    Chapter * chapter2;
    Chapter * chapter3;
    Chapter * chapter7;
		
    int currentChapter = 1;
    
    int widthThirds = 300;
    int widthHalves;
    int widthFull = 1125;
    int heightHalf = 300;
    int heightFull = 700;
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
    string fileName;
    ofImage capture;
    int halfWidth = 400;
    int fullHeight = 500;
    int fullWidth = 850;
    int smallMargin;

};
