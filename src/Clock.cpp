//
//  Clock.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 11/2/15.
//
//

#include "Clock.h"

const ofColor lavender = ofColor(176,183,255);
const ofColor blue = ofColor(178,255,233);
const ofColor red = ofColor(242,105,105);

Clock::Clock(int worldOrUI, int xPos, int yPos){
    this->worldOrUI = worldOrUI;
    this->xPos = xPos;
    this->yPos = yPos;
    
    startingHours = ofGetHours();
    startingMins = ofGetMinutes();
    startingSecs = ofGetSeconds();
}

void Clock:: drawSeconds(){
    ofSetColor(red);
    secs = ofGetElapsedTimef();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationS = secs * 6;
    rotationS += movementFactorS;
    ofRotate(rotationS);
    ofLine(0, -20, 0, 0);
    ofPopMatrix();
    cout<<"secs"<<secs<<endl;
}

void Clock:: drawMinutes(){
    ofSetColor(blue);
    
    mins = secs / 12;
    if (floor(secs/60) ==1){
        mins +=1;
    }
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationM = mins * 30;
    rotationM += movementFactorM;
    ofRotate(rotationM);
    ofLine(0, -15, 0, 0);
    ofPopMatrix();
    
}
void Clock::drawHours(){
    hours = ofGetHours() - startingHours;
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationH = hours * 30;
    rotationH += movementFactorH;
    ofRotate(rotationH);
    ofLine(0, -10, 0, 0);
    ofPopMatrix();
}

