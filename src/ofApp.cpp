#include "ofApp.h"


void ofApp::setup(){
    
    ofEnableDepthTest();
    shader.load("", "random1.frag");
    
    this->chapter0 = new Chapter(0,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
//    this->chapter1 = new Chapter1();
    this->chapter7 = new Chapter(7, 4, 1,1,1,2, 300,300,100,275,250, 300,300,300,687.5,250, 300,300,100,1100,250, 1125,300,100,687.5,625);
    this->chapter1 = new Chapter(1, 1, 2,2,2,2, fullWidth,fullHeight,fullHeight,692.5,425, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0);
    this->chapter2 = new Chapter(2, 4, 1,1,1,1, 200,300,100,250,400, 200,300,100,550,400, 200,300,100,850,400, 200,300,100,1150,400);
    this->chapter3 = new Chapter(3, 2, 1,1,1,1,halfWidth + 125,fullHeight+100,fullHeight-300,400,425, halfWidth+125,fullHeight+100,fullHeight-300,975,425, 0,0,0,0,0, 0,0,0,0,0);
    this->chapter8 = new Chapter(8,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    this->chapter9 = new Chapter(9,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    
    this->sphere1 = new circleFrame(400);
    ofTrueTypeFont::setGlobalDpi(72);
    fileName = "screen1.png";
    chapter7->chapNum = 7;
    chapter0->chapNum = 0;
    chapter1->chapNum = 1;
    chapter2->chapNum = 2;
    chapter3->chapNum = 3;
    chapter8->chapNum = 8;
    chapter9->chapNum = 9;
    this->zerozero = new Characters(390,460,0,0,0);
    this->one = new Characters(350,525,0,1,0);
    this->two = new Characters(350,410,0,1,0);
    this->three = new Characters(350,525,0,1,0);
    this->seven = new Characters(350,285,0,1,0);
    //circular bunny movement
    this->eight = new Characters(-170, 100, 0, 1, 1);
    this->nine = new Characters(600,400,0,1,0);
    this->zero = new Characters(990,570,0,2,0);
    this->playableZero = new Characters(1070, 400,0,0,0);
    this->timer = new Timer();
    
    arcadeFont.loadFont("fonts/arcade/ARCADE.TTF", 24);
    arcadeFont.setLineHeight(20.0f);
    arcadeFont.setLetterSpacing(1.0);
    this->brickChimney = new Item(2, 980, 327);
    this->door = new Item(2,980,526);
    this->clock = new Item(3, 690,250);
    this->homeSign = new Item(2,825,350);
    this->cityScape = new Item(4, 270, 370);
    this->citySlope = new Item(5, 270, 370);
    this->runes1 = new Item(10, 260,300);
    this->cantThinkChapter = new Item(2, 100, 0);
    this->walkToChapter = new Item(2, 0, 200);
    this->UIClock = new Clock(1, ofGetWidth() - 30,  30);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (currentChapter == 1){
        chapter1->update();
    } else if(currentChapter == 2){
        chapter2->update();
    } else if (currentChapter == 3){
        chapter3->update();
    } else if (currentChapter == 7){
        chapter7->update();
    } else if (currentChapter == 8){
        chapter8->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    colorOne.set(bgR1, bgG1, bgB1);
    colorTwo.set(bgR2, bgG2, bgB2);
    
    
//    UIClock->drawHours();
    UIClock -> drawMinutes();
    UIClock -> drawSeconds();
    
    if (abs(UIClock->secs) >= 30 && abs(UIClock->secs) < 45){
        bgR1 = 255 - (UIClock->secs - 30) * 17;
        bgG1 = 255 - (UIClock->secs - 30) * 17;
//        bgB1 = 1 + (UIClock->secs - 30);
//        bgR2 = 1 + (UIClock->secs - 30);
        bgB2 = 255 - (UIClock->secs - 30) * 17;
        bgG2 = 255 - (UIClock->secs - 30) * 17;
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

    } else if (abs(UIClock->secs) > 45 && (abs(UIClock->secs) <= 60)){
        bgB1 = 255 - 255 * (UIClock->secs - 45)/15;
        bgR2 = 255 - 255 * (UIClock ->secs - 45)/15;
        bgR1 = bgG1 = bgG2 = bgB2 = 0;
    }
    else {
        bgR1 = bgR2 = bgG1 = bgG2 = bgB1 = bgB2 = 255;
    }
//    grid->update();
    if (currentChapter == 1){
        chapter1->draw();
        if (chapter1->firstFrame->yRotateState ==0){
            ofPushMatrix();
            ofTranslate(0,0,fullHeight/2 + 1);
            homeSign->xPos = 825;
            homeSign->drawHangingSign();
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(0,0, fullHeight/2+2);
            if (signChanged == false){
                arcadeFont.drawString("Home \nSweet \nHome", 855, 420);
            } else if (signChanged == true){
                arcadeFont.drawString("There \nis No \nEscape", 850, 420);
            }
            ofPopMatrix();
        } else if (chapter1->firstFrame->yRotateState ==1){

//            ofPushMatrix();
//            ofTranslate(0,0,0);
////            ofRotateY(90);
//            homeSign->drawHangingSign();
//            ofPopMatrix();
            
        } else if (chapter1->firstFrame->yRotateState ==2){
//            ofPushMatrix();
//            ofTranslate(0,0,0);
////            ofRotateY(270);
//            //            homeSign->xPos = 325;
//            homeSign->drawHangingSign();
//            ofPushMatrix();
//            ofTranslate(0,0, 1);
//            ofPopMatrix();
            signChanged = true;
        }else if (chapter1->firstFrame->yRotateState ==3){
            //            ofPushMatrix();
            //            ofTranslate(0,0,0);
            ////            ofRotateY(270);
            //            //            homeSign->xPos = 325;
            //            homeSign->drawHangingSign();
            //            ofPushMatrix();
            //            ofTranslate(0,0, 1);
            //            ofPopMatrix();
            signChanged = false;
        }
        one->displacementZ = 251;
        one->display();
        one->move();
        one->jump();
    } else if(currentChapter == 2){
        chapter2->draw();
        

            if (two->location.x > 100 && two->location.x < 300){
                chapter2->activeFrame = 1;
            } else if (two->location.x > 400 && two->location.x < 600){
                chapter2->activeFrame = 2;
            } else if (two->location.x > 700 && two->location.x < 900){
                chapter2->activeFrame = 3;
            } else if (two->location.x > 1000 && two->location.x < 1200){
                chapter2->activeFrame =4;
            }
        
        if(chapter2->firstFrame->yRotateState==2){
            runes1->showRune1 = true;
        } else {runes1->showRune1 = false;}
        if(chapter2->secondFrame->yRotateState==0){
            runes1->showRune2 = true;
        }else{runes1->showRune2 = false;}
        if(chapter2->secondFrame->yRotateState==2){
            runes1->showRune3 = true;
        }else{runes1->showRune3 = false;}
        if(chapter2->thirdFrame->yRotateState==1){
            runes1->showRune4 = true;
        }else{runes1->showRune4 = false;}
        if(chapter2->thirdFrame->yRotateState==2){
            runes1->showRune5= true;
        }else{runes1->showRune5 = false;}
        if(chapter2->fourthFrame->yRotateState==0){
            runes1->showRune6 = true;
        }else{runes1->showRune6 = false;}
        if(chapter2->fourthFrame->yRotateState==2){
            runes1->showRune7 = true;
        }else{runes1->showRune7 = false;}

        
        ofPushMatrix();
        ofTranslate(0, 0, 151);
            runes1->drawRunes();
        ofPopMatrix();
        two->displacementZ = 152;
        two->display();
        two->move();
        two->jump();
    } else if (currentChapter == 3){
        chapter3->draw();
        ofPushMatrix();
        ofTranslate(0, 0, 251);
        cityScape->drawCity();
        if (chapter3->secondFrame->yRotateState ==0){
            citySlope->itemType = 5;
            citySlope->drawCitySlope();
        }
        if (chapter3->secondFrame->yRotateState ==2){
            citySlope->itemType = 4;
            citySlope->drawCitySlope();
        }
        if (chapter3->firstFrame->yRotateState ==0){
            cityScape->itemType = 4;
            cityScape->drawCity();
        }
        if (chapter3->firstFrame->yRotateState ==2){
            cityScape->itemType = 5;
            cityScape->drawCity();
        }
        ofPopMatrix();
        if (chapter3->secondFrame->yRotateState ==0){
            playableZero->zeroUpwards = -1;
            if(playableZero->location.x <=700){
                playableZero->location.x = 700;
            }

        } else if (chapter3->secondFrame->yRotateState ==1 || chapter3->secondFrame->yRotateState ==3){
            playableZero->zeroUpwards = 0;
            if(playableZero->location.x <=700){
                playableZero->location.x = 700;
            }
        } else if (chapter3->secondFrame->yRotateState ==2){
            playableZero->zeroUpwards = 1;
        }
        playableZero->displacementZ = 252;
        playableZero->display();
        playableZero->move();
//        playableZero->jump();
    } else if (currentChapter == 7){
        chapter7->draw();
        
        ofPushMatrix();
        ofTranslate(0, 0, 151);
//            if (int(clock->rotationS)%360 < 15 && int(clock->rotationS)%360 > 0 && door->doorTime == true){
//                if (int(clock->rotationM)%360 < 15 && int(clock->rotationM)%360 > 0 && door->doorTime == true){
//                    if (int(clock->rotationH)%360 < 15 && int(clock->rotationH)%360 > 0 && door->doorTime == true){
//                        if(door->interactionInitiated){
//                                        chapter7->showZero = true;
//                        }
//                    }
//                }
//            }
        ////TOGGLE FOR EASY MODE
                if (int(clock->rotationS)%360 < 15 && int(clock->rotationS)%360 > 0 && door->doorTime == true){
                                            if(door->interactionInitiated){
                                                            chapter7->showZero = true;
                                            }
                }
        
        
                if(chapter7->showZero == true){
                    zero->display();
                    zero->move();
                    chapter7->chimes.play();
                }
                brickChimney->drawChimney();
                if (door->interactionInitiated == false){
                    door->drawClosed();
                }
        
        
                if (seven->moveRight == true){
                    clock->movementFactorS += .5;
        
                }
                if (seven->moveLeft == true){
                    clock->movementFactorS -= .3;
                }
        
                if (seven->location.x < 100 || (seven->location.x>470 && seven->location.x < 500) || (seven->location.x > 800 && seven->location.x < 830) || (seven->location.x > 1200)){
                    seven->location.y += 5;
                    clock->movementFactorH += .1;
                }
        
                if (seven->location.y < seven->startingYpos){
                    clock->movementFactorM += .2;
                }
                if(chapter7->secondFrame->yRotateState ==1){
                    ofSetColor(178,255,233);
                    clock->drawHours();
                    ofSetColor(255);
                    clock->drawMinutes();
                    ofSetColor(242,105,105);
                    clock->drawSeconds();
                }
                if (seven->location.x > 980 && seven->location.x < 1100 && seven->location.y <280 && seven->location.y > 200){
                    chapter7->downTheChimney = true;
                }
                if(chapter7->downTheChimney == true){
                    seven->transported = true;
                }
                if(seven->location.x >= 980 && seven->location.x <= 1100 && seven->location.y > 500){
                    chapter7->appropriateDist = true;
                } else {
                    chapter7->appropriateDist = false;
                }
                if(int(clock->rotationS)%360 < 15 && int(clock->rotationS)%360 > 0){
                    if (door->interactionInitiated == false){
                        door->doorTime = true;
                        chapter7->knock.play();
                    } else {
                        door->doorTime = false;
                    }
                } else {
                    door->doorTime = false;
                }
        
                if (seven->location.y > 500){
                    chapter7->activeFrame = 4;
                } else if (seven->location.y < 500){
                    if (seven->location.x > 100 && seven->location.x < 400){
                        chapter7->activeFrame = 1;
                    } else if (seven->location.x > 500 && seven->location.x < 800){
                        chapter7->activeFrame = 2;
                    } else if (seven->location.x > 900 && seven->location.x < 1200){
                        chapter7->activeFrame = 3;
                    }
                }
            cout << "clock rotationS : " << clock->rotationS << endl;
            cout << "seven location.y? " << seven->location.y << endl;
            cout << "seven location.x? " << seven->location.x << endl;
        
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(0,0, 50);
        seven->displacementZ = 152;
        seven->display();
        seven->move();
        seven->jump();
        ofPopMatrix();
    }
    else if(currentChapter == 8){
//        cam.begin();
//        shader.begin();
//        shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
//        shader.setUniform1f("u_time", ofGetElapsedTimef());
//        sphere1->draw();
//        shader.end();
        eight->circularMove();
//        cam.end();
    }
    else if(currentChapter == 9){
        cantThinkChapter->drawCantthink();
        ofPushMatrix();
        ofTranslate(0,0,500);
        nine->display();
        nine->move();
        nine->jump();
        ofPopMatrix();
        
        if(nine->location.x >= 700){
            cantThinkChapter->thinkStage = 2;
        } else if(nine ->location.x <= 550){
            cantThinkChapter->thinkStage = 3;
        }
    }
    else if(currentChapter ==0){
        walkToChapter->drawWalkTo();
        ofPushMatrix();
        
        if (walkToChapter->idle == false){
            if(ofGetSeconds() % 3 == 1){
                walkToChapter->walkToStage = 1;
            } else if(ofGetSeconds()%4 ==1){
                walkToChapter->walkToStage = 2;
            }
            if (zerozero->location.x >= 920){
                walkToChapter->walkToStage = 3;
            }
        ofTranslate(0,0,240);
        }

        zerozero->display();
        zerozero->move();
        ofPopMatrix();
//        one->jump();
    }

    
    ofSetColor(0);
//    cout << "chapter: " << currentChapter << endl;
//    cout << "frames: " << chapter2->numOfFrames << endl;

    if (currentChapter ==1){
//        one->location.y = 500;
        if (one->location.x > 100 && one->location.x < 1000){
            chapter1->activeFrame = 1;
        } else {
            chapter1->activeFrame = 0;
        }
    }
    else if (currentChapter ==2){
        one->location.y = 400;
//        one->location.x = 200;
        if(one->location.x > 300 && one->location.x < 400){
            if(one->location.y >= 400){
                one->location.y += 2;
            }
        }
    } else if (currentChapter == 3){
//        playableZero->location.y = 400;
        if (playableZero->location.x > 100 && playableZero->location.x < 600){
            chapter3->activeFrame = 1;
        } else if (playableZero->location.x > 700 && playableZero->location.x < 1200){
            chapter3->activeFrame = 2;
        }
    }
    else if(currentChapter == 7){
        if (door->interactionInitiated == true){
            ofPushMatrix();
            ofTranslate(0, 0, 151);
            door->drawOpen();
            ofPopMatrix();
        }
    }
    else if (currentChapter == 8){
        
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    chapter7->keyPressed(key);
    chapter1->keyPressed(key);
    chapter2->keyPressed(key);
    chapter3->keyPressed(key);
    chapter8->keyPressed(key);
    chapter9->keyPressed(key);
    chapter0->keyPressed(key);
    
        if (key == OF_KEY_RIGHT){
            one->moveRight = true;
            two->moveRight = true;
            three->moveRight = true;
            seven->moveRight = true;
            eight->moveRight = true;
            playableZero->moveRight = true;
            zerozero->moveRight = true;
            nine->moveRight = true;

        }
        if (key == OF_KEY_LEFT){
            one->moveLeft = true;
            two->moveLeft = true;
            three->moveLeft = true;
            seven->moveLeft = true;
            eight->moveLeft = true;
            playableZero->moveLeft = true;
            zerozero->moveLeft= true;
            nine->moveLeft = true;

        }
        if (key == OF_KEY_UP){
            one->moveUp = true;
            three->moveUp = true;
            two->moveUp = true;
            seven->moveUp = true;
            eight->moveUp = true;
            playableZero->moveUp = true;

        }
        if (key == OF_KEY_DOWN){
            one->moveDown = true;
            two->moveDown = true;
            three->moveDown = true;
            seven->moveDown = true;
            eight->moveDown = true;
            playableZero->moveDown = true;

        }
        if (key == OF_KEY_RIGHT_SHIFT){
            one->jumped = true;
            three->jumped = true;
            two->jumped = true;
            seven->jumped = true;
            eight->jumped = true;
            playableZero->jumped = true;

        }
    
        if (key == OF_KEY_LEFT_SHIFT){
            if (chapter7->appropriateDist == true){
                if (door->interactionInitiated == false){
                    door->interactionInitiated = true;
                } else {
                    door->interactionInitiated = false;
                }
            } else {
                door->interactionInitiated = false;
            }
        }
//    if(walkToChapter->walkToStage ==0){
        walkToChapter->idle = false;
//    }

}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    chapter1->keyReleased(key);
    chapter2->keyReleased(key);
    chapter3->keyReleased(key);
    chapter7->keyReleased(key);
    chapter8->keyReleased(key);
    chapter9->keyReleased(key);
    chapter0->keyReleased(key);
    
    if (key == OF_KEY_RIGHT){
        one->moveRight = false;
        two->moveRight = false;
        three->moveRight = false;
        nine->moveRight = false;
        seven->moveRight = false;
        eight->moveRight = false;
        playableZero->moveRight = false;
        zerozero->moveRight = false;
    }
    if (key == OF_KEY_LEFT){
        one->moveLeft = false;
        two->moveLeft = false;
        three->moveLeft = false;
        seven->moveLeft = false;
        eight->moveLeft = false;
        playableZero->moveLeft = false;
        zerozero->moveLeft = false;
        nine->moveLeft = false;

    }
    if (key == OF_KEY_UP){
        one->moveUp = false;
        two->moveUp = false;
        three->moveUp = false;
        seven->moveUp = false;
        eight->moveUp = false;
        playableZero->moveUp = false;
    }
    if (key == OF_KEY_DOWN){
        one->moveDown = false;
        three->moveDown = false;
        two->moveDown = false;
        seven->moveDown = false;
        eight->moveDown = false;
        playableZero->moveDown = false;
    }

    if (key == '1'){
        currentChapter = 1;
    } else if (key == '2'){
        currentChapter = 2;
    } else if (key == '3'){
        currentChapter = 3;
    } else if (key == '7'){
        currentChapter = 7;
    } else if (key == '8'){
        currentChapter = 8;
    }else if (key == '9'){
        currentChapter = 9;
    }else if (key == '0'){
        currentChapter = 0;
    }
}
void ofApp::mousePressed(int x, int y, int button){
}
void ofApp::mouseReleased(int x, int y, int button){
}
