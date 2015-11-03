//
//  Characters.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/19/15.
//
//

#include "Characters.hpp"
#define MAXIMAGES 8

ofImage walk[MAXIMAGES];
ofImage walkLeft[MAXIMAGES];
ofImage zeroWalk[MAXIMAGES];
ofImage zeroWalkLeft[MAXIMAGES];

Characters::Characters(float x, float y, float z, int characterMode, int shapeMode){
    location.x = x;
    location.y = y;
    location.z = z;
    this->timer = new Timer();
    this->characterMode = characterMode;
    this->shapeMode = shapeMode;
    normalGravity = ofVec3f(0, 70.0, 0);
    
    startingYpos = location.y;
    
    if (characterMode == 0){
        isPlayer = true;
        isZero = true;
    } else if (characterMode == 1){
        isPlayer = true;
        isOne = true;
        
    } else if (characterMode == 2){
        isAI = true;
        isZero = true;
        
    } else if (characterMode == 3){
        isAI = true;
        isOne = true;
    }
    
    if (characterMode ==1 || characterMode ==3){
        isZero = false;
        walk[0].loadImage("bunnySprite0.png");
        walk[1].loadImage("bunnySprite1.png");
        walk[2].loadImage("bunnySprite2.png");
        walk[3].loadImage("bunnySprite3.png");
        walk[4].loadImage("bunnySprite4.png");
        walk[5].loadImage("bunnySprite5.png");
        walk[6].loadImage("bunnySprite6.png");
        walk[7].loadImage("bunnySprite7.png");
        
        walkLeft[0].loadImage("bunnySpriteLeft0.png");
        walkLeft[1].loadImage("bunnySpriteLeft1.png");
        walkLeft[2].loadImage("bunnySpriteLeft2.png");
        walkLeft[3].loadImage("bunnySpriteLeft3.png");
        walkLeft[4].loadImage("bunnySpriteLeft4.png");
        walkLeft[5].loadImage("bunnySpriteLeft5.png");
        walkLeft[6].loadImage("bunnySpriteLeft6.png");
        walkLeft[7].loadImage("bunnySpriteLeft7.png");
        
        jumpingBunny.loadImage("jumpingBunny.png");
        jumpingBunnyLeft.loadImage("jumpingBunnyLeft.png");
        
        stationaryInCircle.loadImage("circleStationaryBunny.png");
        movingInCircle.loadImage("circleForceBunny.png");
    }
    
    if (isZero == true){
        isOne = false;
        zeroWalk[0].loadImage("zeroBunnySprite0.png");
        zeroWalk[1].loadImage("zeroBunnySprite1.png");
        zeroWalk[2].loadImage("zeroBunnySprite2.png");
        zeroWalk[3].loadImage("zeroBunnySprite3.png");
        zeroWalk[4].loadImage("zeroBunnySprite4.png");
        zeroWalk[5].loadImage("zeroBunnySprite5.png");
        zeroWalk[6].loadImage("zeroBunnySprite6.png");
        zeroWalk[7].loadImage("zeroBunnySprite7.png");

        zeroWalkLeft[0].loadImage("zeroBunnySpriteLeft0.png");
        zeroWalkLeft[1].loadImage("zeroBunnySpriteLeft1.png");
        zeroWalkLeft[2].loadImage("zeroBunnySpriteLeft2.png");
        zeroWalkLeft[3].loadImage("zeroBunnySpriteLeft3.png");
        zeroWalkLeft[4].loadImage("zeroBunnySpriteLeft4.png");
        zeroWalkLeft[5].loadImage("zeroBunnySpriteLeft5.png");
        zeroWalkLeft[6].loadImage("zeroBunnySpriteLeft6.png");
        zeroWalkLeft[7].loadImage("zeroBunnySpriteLeft7.png");
//        jumpingBunny.loadImage("zeroJumpingBunny.png");
    }
}

void Characters::display(){
    if (justJumped != true){
        timer->setup();
    }
    ofSetColor(255,255,255);
    
    if(shapeMode == 0){
    if (ofGetFrameNum() % 7 == 0){
        imageIndex = (imageIndex + 1) % MAXIMAGES;
        location.x += movementSpeed;
        location.y += movementSpeedY;

    }
    
    if (characterMode ==1){
        ofTranslate(0,0,location.z + displacementZ);
        ///////////////////right
        if (moveRight == true){
            movementSpeed = 7;
            if (justJumped == false) {
                walk[imageIndex].draw(location.x, location.y, characterWidth, characterHeight);
                lastMovedRight = true;
                lastMovedLeft = false;
            }
            /////////////////////right + jump
            if (justJumped == true) {
                afterJump = false;
                lastMovedRight = true;
                movementSpeed = 12;
                jumpingBunny.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
                timer->jumpedTime();
                location.y = location.y + jumpForce +(normalGravity.y)*(timer->jumpTimer*timer->jumpTimer);
                if (location.y >= startingYpos) {
                    justJumped = false;
                    afterJump = true;
                }
            }
        }
        /////////////////////left
        if (moveLeft == true) {
            movementSpeed = -7;
            if (justJumped == false){
                walkLeft[imageIndex].draw(location.x, location.y, characterWidth, characterHeight);
                moveRight = false;
                lastMovedRight = false;
                lastMovedLeft = true;
            }
            if (justJumped == true){
                afterJump = false;
                lastMovedLeft = true;
                movementSpeed = -12;
                jumpingBunnyLeft.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
                timer->jumpedTime();
                location.y =location.y + jumpForce +(normalGravity.y)*(timer->jumpTimer*timer->jumpTimer);
                if (location.y >= startingYpos) {
                    justJumped = false;
                    afterJump = true;
                }
            }
        }
        /////////////////////standing still facing right
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && justJumped == false && lastMovedRight == true) {
            movementSpeed = 0;
            walk[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        //////standing still facing left
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && justJumped == false && lastMovedLeft == true) {
            movementSpeed = 0;
            walkLeft[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        /////////////////////standing still start
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && lastMovedRight == false && lastMovedLeft == false) {
            movementSpeed = 0;
            walkLeft[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        
        
        //////////JUMP
        ///facing right
        if (justJumped == true && lastMovedRight == true && moveRight == false) {
            afterJump = false;
            jumpingBunny.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
            timer->jumpedTime();
            location.y = location.y + jumpForce + (normalGravity.y)*(timer->jumpTimer * timer->jumpTimer);
            if (location.y >= startingYpos) {
                justJumped = false;
                afterJump = true;
            }
        }
        //////////JUMP
        ///facing left
        if (justJumped == true && lastMovedLeft == true && moveLeft == false){
            afterJump = false;
            jumpingBunnyLeft.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
            timer->jumpedTime();
            location.y = location.y + jumpForce + (normalGravity.y)*(timer->jumpTimer * timer->jumpTimer);
            if (location.y >= startingYpos) {
                justJumped = false;
                afterJump = true;
            }
        }
        
        if (afterJump == true) {
            cout << "working" << endl;
            timer->reset();
            location.y = startingYpos;
            timer->reset();
            walk[0].draw(location.x, location.y, characterWidth, characterHeight);
            justJumped = false;
            afterJump = false;
        }
    }
    
    if (characterMode ==0){
        ofTranslate(0,0,location.z + displacementZ);
        ///////////////////right
        if (moveRight == true){
            movementSpeed = 7;
            movementSpeedY = zeroUpwards;
            if (justJumped == false) {
                zeroWalk[imageIndex].draw(location.x, location.y, characterWidth, characterHeight);
                lastMovedRight = true;
                lastMovedLeft = false;
            }
            /////////////////////right + jump
            if (justJumped == true) {
                afterJump = false;
                lastMovedRight = true;
                movementSpeed = 9;
                jumpingBunny.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
                timer->jumpedTime();
                location.y = location.y + jumpForce +(normalGravity.y)*(timer->jumpTimer*timer->jumpTimer);
//                if (location.y >= startingYpos) {
//                    justJumped = false;
//                    afterJump = true;
//                }
            }
        }
        /////////////////////left
        if (moveLeft == true) {
            movementSpeed = -7;
            movementSpeedY = -zeroUpwards;
            if (justJumped == false){
                zeroWalkLeft[imageIndex].draw(location.x, location.y, characterWidth, characterHeight);
                moveRight = false;
                lastMovedRight = false;
                lastMovedLeft = true;
            }
            if (justJumped == true){
                afterJump = false;
                lastMovedLeft = true;
                movementSpeed = -9;
                jumpingBunnyLeft.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
                timer->jumpedTime();
                location.y =location.y + jumpForce +(normalGravity.y)*(timer->jumpTimer*timer->jumpTimer);
//                if (location.y >= startingYpos) {
//                    justJumped = false;
//                    afterJump = true;
//                }
            }
        }
        /////////////////////standing still facing right
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && justJumped == false && lastMovedRight == true) {
            movementSpeed = 0;
            movementSpeedY = 0;
            zeroWalk[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        //////standing still facing left
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && justJumped == false && lastMovedLeft == true) {
            movementSpeed = 0;
            movementSpeedY = 0;
            zeroWalkLeft[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        /////////////////////standing still start
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && lastMovedRight == false && lastMovedLeft == false) {
            movementSpeed = 0;
            movementSpeedY = 0;
            zeroWalkLeft[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        
        
//        //////////JUMP
//        ///facing right
//        if (justJumped == true && lastMovedRight == true && moveRight == false) {
//            afterJump = false;
//            jumpingBunny.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
//            timer->jumpedTime();
//            location.y = location.y + jumpForce + (normalGravity.y)*(timer->jumpTimer * timer->jumpTimer);
//            if (location.y >= startingYpos) {
//                justJumped = false;
//                afterJump = true;
//            }
//        }
//        //////////JUMP
//        ///facing left
//        if (justJumped == true && lastMovedLeft == true && moveLeft == false){
//            afterJump = false;
//            jumpingBunnyLeft.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
//            timer->jumpedTime();
//            location.y = location.y + jumpForce + (normalGravity.y)*(timer->jumpTimer * timer->jumpTimer);
//            if (location.y >= startingYpos) {
//                justJumped = false;
//                afterJump = true;
//            }
//        }
//        
//        if (afterJump == true) {
//            cout << "working" << endl;
//            timer->reset();
//            location.y = startingYpos;
//            timer->reset();
//            zeroWalk[0].draw(location.x, location.y, characterWidth, characterHeight);
//            justJumped = false;
//            afterJump = false;
//        }
    }

    if (transported == true){
        location.y = 550;
        startingYpos = 550;
        currentYpos = 550;
//        transported = false;
    }
        
    } else if (shapeMode == 1){
        
    }
}

void Characters::move(){
    if (moveRight == true){
        displacementX += movementSpeed;
        displacementY += movementSpeedY;
    }
    if (moveLeft == true){
        displacementX -= movementSpeed;
        displacementY -= movementSpeedY;
    }
}

void Characters::jump(){
    if (jumped==true) {
        justJumped = true;
        jumped = false;
        timer->jumpedTime();
//        if (location.y >= startingYpos){
//            location.y = startingYpos;
//        }
    }
    
}