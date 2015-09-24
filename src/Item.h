//
//  Item.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/20/15.
//
//

#include "ofMain.h"

class Item{
public:
    Item(int itemType, int xPos, int yPos);
    void drawOpen();
    void drawClosed();
    void drawChimney();
    void drawSeconds();
    void drawMinutes();
    void drawHours();
    
    //0 - cube type; 1 - collectible type; 2 - interaction type; 3 - noCollider type; 4 - collider type
    int itemType;
    
    int xPos;
    int yPos;
    float hours;
    float mins;
    float secs;
    
    float rotationH;
    float rotationM;
    float rotationS;
    
    float movementFactorH = 1.0;
    float movementFactorM = 1.0;
    float movementFactorS = 1.0;
    
    ofImage doorOpen;
    ofImage doorClosed;
    
    ofImage chimney;

    bool interactionInitiated = false;
};