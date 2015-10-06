//
//  Chapter.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 10/3/15.
//
//

#include "Chapter.h"

//int height = 20;
//int width = 30;
//int insideLength = 15;
const ofColor lavender = ofColor(176,183,255);
const ofColor blue = ofColor(178,255,233);
const ofColor red = ofColor(242,105,105);

Chapter::Chapter(int chapNum, int numOfFrames, int frameWidth, int frameHeight, int frameDepth, float marginX, float marginY, int frameWidth2, int frameHeight2, int frameDepth2, float marginX2, float marginY2, int frameWidth3, int frameHeight3, int frameDepth3, float marginX3, float marginY3, int frameWidth4, int frameHeight4, int frameDepth4, float marginX4, float marginY4){
    
    this->frameWidth = frameWidth;
    this->numOfFrames = numOfFrames;
    this->frameHeight = frameHeight;
    this->frameDepth = frameDepth;
    this->marginX = marginX;
    this->marginY = marginY;
    this->marginX2 = marginX2;
    this->marginX3 = marginX3;
    this->marginX4 = marginX4;
    this->marginX2 = marginY2;
    this->marginX3 = marginY3;
    this->marginX4 = marginY4;
    this->frameWidth2 = frameWidth2;
    this->frameWidth3 = frameWidth3;
    this->frameWidth4 = frameWidth4;
    this->frameHeight2 = frameHeight2;
    this->frameHeight3 = frameHeight3;
    this->frameHeight4 = frameHeight4;
    this->frameDepth2 = frameDepth2;
    this->frameDepth3 = frameDepth3;
    this->frameDepth4 = frameDepth4;

    this->chapNum = chapNum;
    
//    if (numOfFrames >=1 ){
        this->firstFrame = new Frame(lavender, blue, blue, frameWidth, frameHeight, frameDepth, marginX, marginY, 1);
//    }
//    if (numOfFrames >=2){
        this->secondFrame = new Frame(lavender, lavender, blue, frameWidth2, frameHeight2, frameDepth2, marginX2,marginY2, 1);
//    }
//    if (numOfFrames >=3){
        this->thirdFrame = new Frame(lavender, blue, red, frameWidth3, frameHeight3, frameDepth3, marginX3, marginX3, 1);
//    }
//    if (numOfFrames >=4){
        this->fourthFrame = new Frame(lavender, red, red, frameWidth4, frameHeight4, frameDepth4, marginX4, marginY4, 2);
//    }
    this->one = new Characters(200,248,0,1);
    this->zero = new Characters(1070,570,0,2);
    this->timer = new Timer();
    this->brickChimney = new Item(2, 1050, 296);
    this->door = new Item(2,1030,540);
    this->clock = new Item(3, 690,200);
//    this->homeSign = new Item(2,825,400);

    //    talk.loadSound("sounds/chimes.wav");
    knock.loadSound("sounds/knock.wav");
    chimes.loadSound("sounds/chimes.wav");
    talk.setVolume(0.75f);
    knock.setVolume(0.75f);
    chimes.setVolume(0.75f);
    //    talk.setMultiPlay(true);
    knock.setMultiPlay(false);
    chimes.setMultiPlay(false);
    
    arcadeFont.loadFont("fonts/arcade/ARCADE.TTF", 30);
    arcadeFont.setLineHeight(20.0f);
    arcadeFont.setLetterSpacing(1.0);

    
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
//    cam1.setDistance(100);
}

//--------------------------------------------------------------
void Chapter::update(){
    ofCamera();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void Chapter::draw(){
    if (numOfFrames >=1 ){
//        cam1.begin();
//        ofRotateX(ofRadToDeg(.5));
//        ofRotateY(ofRadToDeg(-.5));
        firstFrame->display();
        firstFrame->draw();
//        if(cam1.getMouseInputEnabled()) cam1.disableMouseInput();
//        else cam1.enableMouseInput();
//        cam1.end();
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
    one->display();
    one->move();
    one->jump();
    if (chapNum == 1){
        firstFrame->perspectiveMode = 2;
        firstFrame->sideColor = lavender;
        firstFrame->topColor = lavender;
//        if (firstFrame->yRotateState ==0){
//            homeSign->xPos = 825;
//            homeSign->drawHangingSign();
//            arcadeFont.drawString("Home \nSweet \nHome", 850, 500);
//        } else if (firstFrame->yRotateState ==1){
//            ofPushMatrix();
//            ofTranslate(0,0,0);
//            ofRotateY(90);
//            homeSign->drawHangingSign();
//            ofPopMatrix();
//            
//        } else if (firstFrame->yRotateState ==2){
//            ofPushMatrix();
//            ofTranslate(0,0,0);
//            ofRotateY(270);
////            homeSign->xPos = 325;
//            homeSign->drawHangingSign();
//
//            arcadeFont.drawString("There \nis No \nEscape", 850, 500);
//
//            ofPopMatrix();
//
//        }
        one->location.y = 600;
        
        if (one->location.x > 100 && one->location.x < 1000){
            activeFrame = 1;
        } else {
            activeFrame = 0;
        }
    }
    //////////////////////////////CHAPTER 2
    if (chapNum == 2){
        firstFrame->sideColor = red;
        firstFrame->topColor = lavender;
        secondFrame->frontColor = red;
        secondFrame->sideColor = lavender;
        secondFrame->topColor = lavender;
        secondFrame->boxWidth = 100;
        secondFrame->boxHeight = 100;
        secondFrame->boxDepth = 100;
        secondFrame->marginX = 100 * 2 + 100;
        secondFrame->marginY = 100;
        one->location.y = 600;
        one->location.x = 200;
        
        if(one->location.x > 300 && one->location.x < 400){
            if(one->location.y >= 400){
                one->location.y += 2;
            }
        }
    }
    
    if (chapNum == 3){
        firstFrame->frontColor = blue;
        firstFrame->sideColor = blue;
        firstFrame->topColor = red;
        
    }
    if (chapNum == 7){
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
    cout << "rotationS : " << clock->rotationS << endl;
    cout << "location.y? " << one->location.y << endl;
    cout << "location.x? " << one->location.x << endl;
    }
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
