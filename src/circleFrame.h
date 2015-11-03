//
//  circleFrame.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 11/2/15.
//
//

#include "ofMain.h"

class circleFrame{
public:
    circleFrame(float width);
    void draw();
    
    float width;
    
    ofSpherePrimitive sphere;
};