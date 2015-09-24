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
ofImage zeroWalk[MAXIMAGES];

Characters::Characters(float x, float y, float z, int characterMode){
    location.x = x;
    location.y = y;
    location.z = z;
    this->characterMode = characterMode;
//    for(int i = 0; i < MAXIMAGES; i++){
////        ofJoinString("bunnySprite", ".png");
//        walk[i].loadImage("bunnySprite" + i + ".png");
//    }
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
    
        jumpingBunny.loadImage("jumpingBunny.png");
        
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
        
        jumpingBunny.loadImage("zeroJumpingBunny.png");
    }

}

void Characters::display(){
    ofSetColor(255,255,255);
//    ofPushMatrix();
    if (ofGetFrameNum() % 7 == 0){
        imageIndex = (imageIndex + 1) % MAXIMAGES;
        location.x += movementSpeed;

    }
//    ofTranslate(ofGetWidth()/2 + displacementX, ofGetHeight()/2 + displacementY, startingZpos + displacementZ);
//
//    ofTranslate(ofGetWidth()/2 + location.x + displacementX ,ofGetHeight()/2 +  location.y + displacementY);
//        ofPopMatrix();

    
    if (isPlayer == true){
        ///////////////////right
        if (moveRight == true){
            movementSpeed = 4;
            if (justJumped == false) {
                walk[imageIndex].draw(location.x, location.y, characterWidth, characterHeight);
                lastMovedRight = true;
                lastMovedLeft = false;
            }
            if (justJumped == true) {
                afterJump = false;
                jumpingBunny.draw(location.x, location.y, characterWidth + 15, characterHeight - 10);
    //            location.y = location.y + jumpForce +(normalGravity.y)*(timer.jumpTimer*timer.jumpTimer);
    //            println(location.y);
                if (location.y >= startingYpos) {
                    justJumped = false;
                    afterJump = true;
                }
            }
        }
        /////////////////////left
        if (moveLeft == true) {
            movementSpeed = -4;
//            ofScale(-1, 1);
            walk[imageIndex].mirror(false, true);
            walk[imageIndex].draw(location.x, location.y, characterWidth, characterHeight);
            lastMovedRight = false;
            lastMovedLeft = true;
        }

        /////////////////////standing still facing right
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && justJumped == false && lastMovedRight == true) {
            movementSpeed = 0;
            walk[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        /////////////////////standing still start
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && lastMovedRight == false && lastMovedLeft == false) {
            movementSpeed = 0;
            walk[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
    }
    
    if(isZero == true){
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && justJumped == false && lastMovedRight == true) {
            //        rotateX(angle);
            zeroWalk[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
        /////////////////////standing still start
        if (moveRight == false && moveLeft == false && moveUp == false && moveDown == false && lastMovedRight == false && lastMovedLeft == false) {
            //        rotateX(angle);
            zeroWalk[0].draw(location.x, location.y, characterWidth, characterHeight);
        }
    }

}

void Characters::move(){
    if (moveRight == true){
        displacementX += movementSpeed;
    }
    if (moveLeft == true){
        displacementX -= movementSpeed;
    }
}

void Characters::jump(){
    if (jumped==true) {
        afterJump = true;
        jumped = false;
        if (location.y >= startingYpos){
            location.y = startingYpos;
        }
    }
    
}