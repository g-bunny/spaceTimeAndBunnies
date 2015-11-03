//
//  Chapter.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 10/3/15.
//
//

#include "Chapter.h"

const ofColor lavender = ofColor(176,183,255);
const ofColor blue = ofColor(178,255,233);
const ofColor red = ofColor(242,105,105);

Chapter::Chapter(int chapNum, int numOfFrames, int persp1, int persp2, int persp3, int persp4,
                 int frameWidth, int frameHeight, int frameDepth, float marginX, float marginY,
                 int frameWidth2, int frameHeight2, int frameDepth2, float marginX2, float marginY2,
                 int frameWidth3, int frameHeight3, int frameDepth3, float marginX3, float marginY3,
                 int frameWidth4, int frameHeight4, int frameDepth4, float marginX4, float marginY4){
    
    this->frameWidth = frameWidth;
    this->numOfFrames = numOfFrames;
    this->frameHeight = frameHeight;
    this->frameDepth = frameDepth;
    this->marginX = marginX;
    this->marginY = marginY;
    
    this->persp1 = persp1;
    this->persp2 = persp2;
    this->persp3 = persp3;
    this->persp4 = persp4;
    
    this->frameWidth2 = frameWidth2;
    this->frameHeight2 = frameHeight2;
    this->frameDepth2 = frameDepth2;
    this->marginX2 = marginX2;
    this->marginY2 = marginY2;
    
    this->frameWidth3 = frameWidth3;
    this->frameHeight3 = frameHeight3;
    this->frameDepth3 = frameDepth3;
    this->marginX3 = marginX3;
    this->marginY3 = marginY3;


    this->frameWidth4 = frameWidth4;
    this->frameHeight4 = frameHeight4;
    this->frameDepth4 = frameDepth4;
    this->marginX4 = marginX4;
    this->marginY4 = marginY4;
    
    this->chapNum = chapNum;
    
        this->firstFrame = new Frame(lavender, blue, blue, frameWidth, frameHeight, frameDepth, marginX, marginY, persp1);
        this->secondFrame = new Frame(lavender, lavender, blue, frameWidth2, frameHeight2, frameDepth2, marginX2,marginY2, persp2);
        this->thirdFrame = new Frame(lavender, blue, red, frameWidth3, frameHeight3, frameDepth3, marginX3, marginY3, persp3);
        this->fourthFrame = new Frame(lavender, lavender, red, frameWidth4, frameHeight4, frameDepth4, marginX4, marginY4, persp4);
    knock.loadSound("sounds/knock.wav");
    chimes.loadSound("sounds/chimes.wav");
    talk.setVolume(0.75f);
    knock.setVolume(0.75f);
    chimes.setVolume(0.75f);
    knock.setMultiPlay(false);
    chimes.setMultiPlay(false);
    
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
//    cam1.setDistance(100);
}

//--------------------------------------------------------------
void Chapter::update(){
    ofCamera();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void Chapter::draw(){
    if (numOfFrames >=1 ){
//        cam1.begin();
//        ofRotateX(ofRadToDeg(.5));
//        ofRotateY(ofRadToDeg(-.5));
        firstFrame->draw(persp1);
//        if(cam1.getMouseInputEnabled()) cam1.disableMouseInput();
//        else cam1.enableMouseInput();
//        cam1.end();
    }
    if (numOfFrames >=2 ){
        secondFrame->draw(persp2);
    }
    if (numOfFrames >=3 ){
        thirdFrame->draw(persp3);
    }
    if (numOfFrames >=4 ){
        fourthFrame->draw(persp4);
    }

    if (chapNum == 1){
        firstFrame->sideColor = lavender;
        firstFrame->topColor = lavender;
    }

    if (chapNum == 2){
        firstFrame->sideColor = red;
        firstFrame->topColor = lavender;
        secondFrame->frontColor = red;
        secondFrame->sideColor = lavender;
        secondFrame->topColor = lavender;
    }
    
    if (chapNum == 3){
        firstFrame->frontColor = blue;
        firstFrame->sideColor = blue;
        firstFrame->topColor = red;
        secondFrame->frontColor = blue;
    }
    if (chapNum == 4){
        firstFrame->frontColor = lavender;
        firstFrame->sideColor = blue;
        firstFrame->topColor = lavender;
    }
    if (chapNum == 7){
    }
}

//--------------------------------------------------------------
void Chapter::keyPressed(int key){
}

//--------------------------------------------------------------
void Chapter::keyReleased(int key){
    if (key == 'd'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipRight = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipRight = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipRight = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipRight = true;
        }
    }
    if (key == 'a'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipLeft = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipLeft = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipLeft = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipLeft = true;
        }
    }
    if (key == 'w'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipUp = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipUp = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipUp = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipUp = true;
        }
    }
    if (key == 's'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipDown = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipDown = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipDown = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipDown = true;
        }
    }
}
