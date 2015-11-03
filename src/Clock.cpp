//
//  Clock.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 11/2/15.
//
//

#include "Clock.h"

Clock::Clock(int worldOrUI, int xPos, int yPos){
    this->worldOrUI = worldOrUI;
    this->xPos = xPos;
    this->yPos = yPos;
}

void Clock:: drawSeconds(){
    
    secs = ofGetSeconds();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationS = secs * 6;
    rotationS += movementFactorS;
    ofRotate(rotationS);
    ofLine(0, -140, 0, 0);
    ofPopMatrix();
}

void Clock:: drawMinutes(){
    mins = ofGetMinutes();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationM = mins * 6;
    rotationM += movementFactorM;
    ofRotate(rotationM);
    ofLine(0, -120, 0, 0);
    ofPopMatrix();
    
}
void Clock::drawHours(){
    hours = ofGetHours();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationH = hours * 30;
    rotationH += movementFactorH;
    ofRotate(rotationH);
    ofLine(0, -100, 0, 0);
    ofPopMatrix();
}

