//
//  Item.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/20/15.
//
//

#include "Item.h"

Item:: Item(int itemType, int xPos, int yPos){
    this->xPos = xPos;
    this->yPos = yPos;
    doorOpen.loadImage("doorOpen.png");
    doorClosed.loadImage("doorClosed.png");
    chimney.loadImage("brickChimney.png");
    hangingSign.loadImage("hangingSign.png");
    groundedSign.loadImage("groundedSignWithout.png");
    groundedSign2.loadImage("groundedSignWithDrawing.png");
}

void Item:: drawOpen(){
    ofSetColor(255,255,255,255);
    doorOpen.draw(xPos - 81,yPos,225,259);
}

void Item:: drawClosed(){
    ofSetColor(255,255,255,255);
    shake = ofRandom(-2, 2);
    if (doorTime == false){
        doorClosed.draw(xPos, yPos, 144, 210);
    }
    if (doorTime == true){
        doorClosed.draw(xPos + shake, yPos + shake, 144, 210);
    }

}

void Item:: drawChimney(){
    ofSetColor(255,255,255,255);
    chimney.draw(xPos, yPos, 158, 102);
    
}

void Item:: drawSeconds(){
    
    secs = ofGetSeconds();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationS = secs * 6;
    rotationS += movementFactorS;
    ofRotate(rotationS);
    ofLine(0, -140, 0, 0);
    ofPopMatrix();
}

void Item:: drawMinutes(){
    mins = ofGetMinutes();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationM = mins * 6;
    rotationM += movementFactorM;
    ofRotate(rotationM);
    ofLine(0, -120, 0, 0);
    ofPopMatrix();
    
}
void Item::drawHours(){
    hours = ofGetHours();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationH = hours * 30;
    rotationH += movementFactorH;
    ofRotate(rotationH);
    ofLine(0, -100, 0, 0);
    ofPopMatrix();
}

void Item::drawHangingSign(){
    ofSetColor(255,255,255,255);
    hangingSign.draw(xPos, yPos, 151.2, 150);
}

void Item::drawGroundedSign(){
    ofSetColor(255,255,255,255);
    groundedSign.draw(xPos, yPos, 150, 150);
}

void Item::drawGroundedSign2(){
    ofSetColor(255,255,255,255);
    groundedSign.draw(xPos, yPos, 150, 150);
}