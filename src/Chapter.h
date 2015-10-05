//
//  Chapter.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 10/3/15.
//
//
#include "ofMain.h"
#include "Frame.hpp"
#include "Characters.hpp"
#include "Item.h"
#include "cubeItems.h"
#define HOURLENGTH 4
#define MINLENGTH 5
#define SECLENGTH 6

class Chapter{
public:
    Chapter(int chapNum, int numOfFrames, int frameWidth, int frameHeight, int frameDepth, float marginX, float marginY, string objectsPlaced1, string objectsPlaced2);
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
    int activeFrame = 0;
    int numOfFrames;
    int frameWidth;
    int frameHeight;
    int frameDepth;
    float marginX;
    float marginY;
    int chapNum = 0;
    string objectsPlaced1;
    string objectsPlaced2;

};
