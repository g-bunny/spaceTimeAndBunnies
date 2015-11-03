//
//  circleFrame.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 11/2/15.
//
//

#include "circleFrame.h"

circleFrame::circleFrame(float width){
    this->width = width;
    sphere.setRadius(width);
}

void circleFrame::draw(){
    float spinX = sin(ofGetElapsedTimef()*.035f) * 0.01;
    float spinY = cos(ofGetElapsedTimef()*.075f) * 0.01;
    sphere.setPosition(ofGetWidth() *.5, ofGetHeight() * .5, 0);
    
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    sphere.setScale(.60f);
    ofSetColor(0,0,0);
//    sphere.drawWireFrame();
    
    sphere.draw();
    
}