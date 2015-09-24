
//
//  Timer.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/21/15.
//
//

#include "Timer.h"

Timer::Timer(){
    
}

void Timer::setup(){
    initialTime = ofGetElapsedTimef();
}

void Timer::jumpedTime(){
    jumpTimer = ofGetElapsedTimef() - initialTime;
//    if (one->justJumped== false){
//    }

}

void Timer::reset(){
    initialTime = ofGetElapsedTimef();

}