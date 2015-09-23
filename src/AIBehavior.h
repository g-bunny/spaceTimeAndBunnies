//
//  AIBehavior.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/22/15.
//
//

#include "ofMain.h"

class AIBehavior {
public:
    AIBehavior();
    void update();
    void jumpedTime();
    void reset();
    
    float jumpTimer;
    float gameTimer;
    float levelTimer;
    float itemTimer;
    
    float initialTime;
    float elapsedTime;
    
};