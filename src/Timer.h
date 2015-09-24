//
//  Timer.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/21/15.
//
//

#include "ofMain.h"

class Timer {
public:
    Timer();
    void setup();
    void jumpedTime();
    void reset();
    
    float jumpTimer;
    float gameTimer;
    float levelTimer;
    float itemTimer;
    
    float initialTime;
    float elapsedTime;
    
};