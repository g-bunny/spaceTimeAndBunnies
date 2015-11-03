//
//  Clock.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 11/2/15.
//
//

#include "ofMain.h"

class Clock{
public:
    Clock(int worldOrUI, int xPos, int yPos);
    
    int worldOrUI; //world =0; UI =1;
    void drawSeconds();
    void drawMinutes();
    void drawHours();

    int xPos;
    int yPos;
    
    float hours;
    float mins;
    float secs;
    
    float rotationH;
    float rotationM;
    float rotationS;
    
    float movementFactorH = 0.0;
    float movementFactorM = 0.0;
    float movementFactorS = 0.0;

};