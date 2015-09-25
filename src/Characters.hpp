//
//  Characters.hpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/19/15.
//
//

#include "ofMain.h"
#include "Timer.h"

class Characters{
public:
    Characters(float x, float y, float z, int characterMode);
    void display();
    void move();
    void jump();
    
    
    float x, y, z;
    int maxImages = 8;
    int imageIndex = 0;
    
    float smallNumber = -150;
    float bigNumber = 150;
    
    float displacementX = 0;
    float displacementY = 0;
    float displacementZ = 0;
    
    float movementSpeed = 0;
    bool lastMovedRight = false;
    bool lastMovedLeft = false;
    bool afterJump = false;
    bool jumped = false;
    bool justJumped = false;
    ofVec3f location;
    ofVec3f velocity;
    ofVec3f acceleration;
    
    float characterWidth = 75.0;
    float characterHeight = 150.0;
    
    float startingXpos = smallNumber + characterWidth/2;
    float startingYpos = bigNumber - characterHeight/2;
    float startingZpos;
    
    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    
    ofImage jumpingBunny;
    ofImage jumpingBunnyLeft;
    
    
    bool isOne = false;
    bool isZero = false;
    bool isPlayer = false;
    bool isAI = false;
    
    bool transported = false;
    
    int characterMode;
    
    float currentYpos = startingYpos;
    
    ofVec3f normalGravity;
    float jumpForce = -11;
    
    Timer * timer;
    
    // 0 = isZero & isPlayer, 1 = isOne & isPlayer, 2 = isZero & isAI, 3 = isOne & isAI
};