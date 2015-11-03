#pragma once

#include "ofMain.h"
#include "Chapter.h"
#include "Item.h"
#include "Characters.hpp"
#include "Grid.h"
#include "Clock.h"
#include "circleFrame.h"

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
    
    Characters * one;
    Characters * two;
    Characters * three;
    Characters * seven;
    Characters * zero;
    Characters * playableZero;
    
    Grid * grid;
    
    Item * door;
    Item * brickChimney;
    Item * clock;
    Item * homeSign;
    Item * groundSign;
    Item * cityScape;
    Item * citySlope;
    Item * runes1;
    Item * runes2;
    Item * runes3;
    Item * runes4;
    Item * runes5;
    Item * runes6;
    Item * runes7;

    Timer * timer;
    
    ofTrueTypeFont arcadeFont;
    ofTrueTypeFont visitorFont;
    ofTrueTypeFont superScriptFont;
    ofTrueTypeFont handyFont;
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

    bool signChanged = false;
    
    bool grounded;
    int minGround;
    int maxGround;
    circleFrame * sphere1;
    
    ofShader shader;
    ofEasyCam cam;
};
