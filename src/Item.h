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
    void drawHangingSign();
    void drawGroundedSign();
    void drawGroundedSign2();
    void drawCity();
    void drawCitySlope();
    void drawRunes();
    void drawCantthink();
    void drawWalkTo();
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
    
    float movementFactorH = 0.0;
    float movementFactorM = 0.0;
    float movementFactorS = 0.0;
    
    ofImage doorOpen;
    ofImage doorClosed;
    
    ofImage chimney;
    ofImage hangingSign;
    ofImage groundedSign;
    ofImage groundedSign2;
    ofImage cityScape;
    ofImage cityScapeFlip;
    ofImage citySlope;
    ofImage citySlopeFlip;
    
    ofImage runes1;
    ofImage runes2;
    ofImage runes3;
    ofImage runes4;
    ofImage runes5;
    ofImage runes6;
    ofImage runes7;
    
    ofImage cantthink1;
    ofImage cantthink2;
    ofImage cantthink3;
    
    ofImage walkTo0;
    ofImage walkTo1;
    ofImage walkTo2;
    ofImage walkTo3;
    
    
    float scalingDown = .75;
    
    float shake;
    bool interactionInitiated = false;
    bool doorTime = false;
    
    bool showRune1 = false;
    bool showRune2 = false;
    bool showRune3 = false;
    bool showRune4 = false;
    bool showRune5 = false;
    bool showRune6 = false;
    bool showRune7 = false;
    
    int thinkStage = 1;
    
    int walkToStage = 0;
    
    bool idle = true;
    
    
};