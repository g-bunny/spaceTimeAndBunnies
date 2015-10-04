//
//  Chapter.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 10/3/15.
//
//

#include "Chapter.h"

int height = 20;
int width = 30;
int insideLength = 15;

Chapter::Chapter(int numOfFrames, int frameWidth, int frameHeight, int frameDepth, int marginX, int marginY, string objectsPlaced1, string objectsPlaced2){
    const ofColor lavender = ofColor(176,183,255);
    const ofColor blue = ofColor(178,255,233);
    const ofColor red = ofColor(242,105,105);
    this->frameWidth = frameWidth;
    this->numOfFrames = numOfFrames;
    this->frameHeight = frameHeight;
    this->frameDepth = frameDepth;
    this->marginX = marginX;
    this->marginY = marginY;
    this->objectsPlaced1 = objectsPlaced1;
    this->objectsPlaced2 = objectsPlaced2;
//    if (numOfFrames >=1 ){
        this->firstFrame = new Frame(lavender, blue, blue, frameWidth, frameHeight, frameDepth, marginX, marginY, 1);
//    }
//    if (numOfFrames >=2){
        this->secondFrame = new Frame(lavender, lavender, blue, 300, 300, 300, 687.5,250, 1);
//    }
//    if (numOfFrames >=3){
        this->thirdFrame = new Frame(lavender, blue, red, 300, 300, 100, 1100, 250, 1);
//    }
//    if (numOfFrames >=4){
        this->fourthFrame = new Frame(lavender, red, red, 1125, 300, 100, 687.5, 625, 2);
//    }
    this->one = new Characters(200,248,0,1);
    this->zero = new Characters(1070,570,0,2);
    this->timer = new Timer();
    this->brickChimney = new Item(2, 1050, 296);
    this->door = new Item(2,1030,540);
    this->clock = new Item(3, 690,200);
    //    talk.loadSound("sounds/chimes.wav");
    knock.loadSound("sounds/knock.wav");
    chimes.loadSound("sounds/chimes.wav");
    talk.setVolume(0.75f);
    knock.setVolume(0.75f);
    chimes.setVolume(0.75f);
    //    talk.setMultiPlay(true);
    knock.setMultiPlay(false);
    chimes.setMultiPlay(false);
    ofBackground(255);
}

//--------------------------------------------------------------
void Chapter::update(){
    ofCamera();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void Chapter::draw(){
    if (numOfFrames >=1 ){
        firstFrame->display();
        firstFrame->draw();
    }
    if (numOfFrames >=2 ){
        secondFrame->display();
        secondFrame->draw();
    }
    if (numOfFrames >=3 ){
        thirdFrame->display();
        thirdFrame->draw();
    }
    if (numOfFrames >=4 ){
        fourthFrame->display();
        fourthFrame->draw();
    }

    if (door->interactionInitiated == true){
        door->drawOpen();
    }
    //    if (int(clock->rotationS)%360 < 15 && int(clock->rotationS)%360 > 0 && door->doorTime == true){
    //        if (int(clock->rotationM)%360 < 15 && int(clock->rotationM)%360 > 0 && door->doorTime == true){
    //            if (int(clock->rotationH)%360 < 15 && int(clock->rotationH)%360 > 0 && door->doorTime == true){
    //                if(door->interactionInitiated){
    //                                showZero = true;
    //                }
    //            }
    //        }
    //    }
    //////TOGGLE FOR EASY MODE
    if (int(clock->rotationS)%360 < 15 && int(clock->rotationS)%360 > 0 && door->doorTime == true){
        showZero = true;
    }
    
    
    if(showZero == true){
        zero->display();
        zero->move();
        chimes.play();
        
    }
    
    brickChimney->drawChimney();
    if (door->interactionInitiated == false){
        door->drawClosed();
    }
    one->display();
    one->move();
    one->jump();
    
    if (one->moveRight == true){
        clock->movementFactorS += .5;
        
    }
    if (one->moveLeft == true){
        clock->movementFactorS -= .3;
    }
    
    if (one->location.x < 100 || (one->location.x>400 && one->location.x < 500) || (one->location.x > 800 && one->location.x < 900) || (one->location.x > 1200)){
        clock->movementFactorH += .1;
    }
    
    if (one->location.y < one->startingYpos){
        clock->movementFactorM += .2;
    }
    if(secondFrame->yRotateState ==1){
        ofSetColor(178,255,233);
        clock->drawHours();
        ofSetColor(255);
        clock->drawMinutes();
        ofSetColor(242,105,105);
        clock->drawSeconds();
    }
    
    if (one->location.x > 1030 && one->location.x < 1130 && one->location.y <215 && one->location.y > 190){
        downTheChimney = true;
    }
    
    if(downTheChimney == true){
        one->transported = true;
    }
    
    if(one->location.x >= 1010 && one->location.x <= 1150 && one->location.y == 625){
        appropriateDist = true;
    } else {
        appropriateDist = false;
    }
    
    if(int(clock->rotationS)%360 < 15 && int(clock->rotationS)%360 > 0){
        if (door->interactionInitiated == false){
            door->doorTime = true;
            knock.play();
        } else {
            door->doorTime = false;
        }
    } else {
        door->doorTime = false;
    }
    
    
    if (one->location.y > 500){
        activeFrame = 4;
    } else if (one->location.y < 500){
        if (one->location.x > 100 && one->location.x < 400){
            activeFrame = 1;
        } else if (one->location.x > 500 && one->location.x < 800){
            activeFrame = 2;
        } else if (one->location.x > 900 && one->location.x < 1200){
            activeFrame = 3;
        }
    }
    
    //    cout << "mins " << clock->mins << endl;
    cout << "rotationS : " << clock->rotationS << endl;
    cout << "location.y? " << one->location.y << endl;
    cout << "location.x? " << one->location.x << endl;
    
}

//--------------------------------------------------------------
void Chapter::keyPressed(int key){
    if (key == OF_KEY_RIGHT){
        one->moveRight = true;
    }
    if (key == OF_KEY_LEFT){
        one->moveLeft = true;
    }
    if (key == OF_KEY_UP){
        one->moveUp = true;
    }
    if (key == OF_KEY_DOWN){
        one->moveDown = true;
    }
    if (key == OF_KEY_RIGHT_SHIFT){
        one->jumped = true;
    }
    if (key == OF_KEY_LEFT_SHIFT){
        if (appropriateDist == true){
            if (door->interactionInitiated == false){
                door->interactionInitiated = true;
            } else {
                door->interactionInitiated = false;
            }
        } else {
            door->interactionInitiated = false;
        }
    }
    
}

//--------------------------------------------------------------
void Chapter::keyReleased(int key){
    if (key == 'd'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipRight = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipRight = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipRight = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipRight = true;
        }
    }
    if (key == 'a'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipLeft = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipLeft = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipLeft = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipLeft = true;
        }
    }
    if (key == 'w'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipUp = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipUp = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipUp = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipUp = true;
        }
    }
    if (key == 's'){
        if(activeFrame ==1 && numOfFrames >=1){
            firstFrame->flipDown = true;
        } else if(activeFrame == 2 && numOfFrames >=2){
            secondFrame->flipDown = true;
        } else if(activeFrame == 3 && numOfFrames >=3){
            thirdFrame->flipDown = true;
        } else if(activeFrame == 4 && numOfFrames >=4){
            fourthFrame->flipDown = true;
        }
    }
    if (key == OF_KEY_RIGHT){
        one->moveRight = false;
    }
    if (key == OF_KEY_LEFT){
        one->moveLeft = false;
    }
    if (key == OF_KEY_UP){
        one->moveUp = false;
    }
    if (key == OF_KEY_DOWN){
        one->moveDown = false;
    }
}
