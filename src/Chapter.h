//
//  Chapter.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 10/3/15.
//
//
#include "ofMain.h"
#include "Frame.hpp"
//#include "Characters.hpp"
//#include "Item.h"
#include "cubeItems.h"
#define HOURLENGTH 4
#define MINLENGTH 5
#define SECLENGTH 6

class Chapter{
public:
    Chapter(int chapNum, int numOfFrames, int persp1, int persp2, int persp3, int persp4, int frameWidth, int frameHeight, int frameDepth, float marginX, float marginY, int frameWidth2, int frameHeight2, int frameDepth2, float marginX2, float marginY2, int frameWidth3, int frameHeight3, int frameDepth3, float marginX3, float marginY3, int frameWidth4, int frameHeight4, int frameDepth4, float marginX4, float marginY4);
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    Frame * firstFrame;
    Frame * secondFrame;
    Frame * thirdFrame;
    Frame * fourthFrame;
    Frame * hourFrames[HOURLENGTH];
    Frame * minFrames[MINLENGTH];
    Frame * secFrames[SECLENGTH];
//    Characters * one;
//    Characters * zero;
//    Timer * timer;
    ofSoundPlayer talk;
    ofSoundPlayer knock;
    ofSoundPlayer chimes;

    
    float hourIncrement = 0.5;
    float minIncrement = 1;
    float secIncrement = 6;
    
    bool downTheChimney = false;
    bool appropriateDist = false;
    
    bool showZero = false;
    int activeFrame = 0;
        
    int numOfFrames;
    int frameWidth;
    int frameHeight;
    int frameDepth;
    float marginX;
    float marginY;
    int frameWidth2;
    int frameHeight2;
    int frameDepth2;
    int frameWidth3;
    int frameHeight3;
    int frameDepth3;
    int frameWidth4;
    int frameHeight4;
    int frameDepth4;
    float marginX2;
    float marginY2;
    float marginX3;
    float marginY3;
    float marginX4;
    float marginY4;
    int chapNum = 0;
    string objectsPlaced1;
    string objectsPlaced2;
    
    
    int persp1, persp2, persp3, persp4;
    

    
    
//    ofEasyCam cam1;

};
