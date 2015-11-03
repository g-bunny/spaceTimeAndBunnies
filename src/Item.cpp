//
//  Item.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/20/15.
//
//

#include "Item.h"

Item:: Item(int itemType, int xPos, int yPos){
    this->xPos = xPos;
    this->yPos = yPos;
    doorOpen.loadImage("doorOpen.png");
    doorClosed.loadImage("doorClosed.png");
    chimney.loadImage("brickChimney.png");
    hangingSign.loadImage("hangingSign.png");
    groundedSign.loadImage("groundedSignWithout.png");
    groundedSign2.loadImage("groundedSignWithDrawing.png");
    cityScape.loadImage("cityScape_small.png");
    cityScapeFlip.loadImage("cityScapeFlip.png");
    citySlope.loadImage("citySlope.png");
    citySlopeFlip.loadImage("citySlopeFlip.png");
    runes1.loadImage("1.1.png");
    runes2.loadImage("2.1.png");
    runes3.loadImage("3.1.png");
    runes4.loadImage("4.1.png");
    runes5.loadImage("5.1.png");
    runes6.loadImage("6.1.png");
    runes7.loadImage("7.1.png");
    
    cantthink1.loadImage("icantthink_blank.png");
    cantthink2.loadImage("icantthink_stage1.png");
    cantthink3.loadImage("icantthink_stage2.png");
    walkTo0.loadImage("walkToNextFrame0.png");
    walkTo1.loadImage("walkToNextFrame1.png");
    walkTo2.loadImage("walkToNextFrame2.png");
    walkTo3.loadImage("walkToNextFrame3.png");

}

void Item:: drawOpen(){
    ofSetColor(255,255,255,255);
    doorOpen.draw(xPos - 71 ,yPos,225* scalingDown,259* scalingDown);
}

void Item:: drawClosed(){
    ofSetColor(255,255,255,255);
    shake = ofRandom(-2, 2);
    if (doorTime == false){
        doorClosed.draw(xPos, yPos, 144 * scalingDown, 210* scalingDown);
    }
    if (doorTime == true){
        doorClosed.draw(xPos + shake, yPos + shake, 144* scalingDown, 210* scalingDown);
    }
}

void Item:: drawChimney(){
    ofSetColor(255,255,255,255);
    chimney.draw(xPos, yPos, 158* scalingDown, 102* scalingDown);
}

void Item:: drawSeconds(){
    
    secs = ofGetSeconds();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationS = secs * 6;
    rotationS += movementFactorS;
    ofRotate(rotationS);
    ofLine(0, -140, 0, 0);
    ofPopMatrix();
}

void Item:: drawMinutes(){
    mins = ofGetMinutes();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationM = mins * 6;
    rotationM += movementFactorM;
    ofRotate(rotationM);
    ofLine(0, -120, 0, 0);
    ofPopMatrix();
    
}
void Item::drawHours(){
    hours = ofGetHours();
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    rotationH = hours * 30;
    rotationH += movementFactorH;
    ofRotate(rotationH);
    ofLine(0, -100, 0, 0);
    ofPopMatrix();
}

void Item::drawHangingSign(){
    ofSetColor(255,255,255,255);
    hangingSign.draw(xPos, yPos, 151.2 * scalingDown, 150* scalingDown);
}

void Item::drawGroundedSign(){
    ofSetColor(255,255,255,255);
    groundedSign.draw(xPos, yPos, 150* scalingDown, 150* scalingDown);
}

void Item::drawGroundedSign2(){
    ofSetColor(255,255,255,255);
    groundedSign.draw(xPos, yPos, 150, 150);
}

void Item::drawCity(){
    ofSetColor(255,255,255,255);
    if (itemType ==4){
        cityScape.draw(xPos-1, yPos+5, 400, 280);
    } else if (itemType ==5){
        cityScapeFlip.draw(xPos-1, yPos+5, 400, 280);
    }
}

void Item::drawCitySlope(){
    ofSetColor(255,255,255,255);
    if (itemType == 4){
        citySlope.draw(xPos + 438, yPos-5, 400, 290);
    } else if (itemType == 5){
        citySlopeFlip.draw(xPos + 438, yPos-5, 400, 290);
    }
}
void Item::drawRunes(){
    ofSetColor(255,255,255,255);
    if (showRune1 ==true){
    runes1.draw(xPos, yPos, 120,201);
    }
    if (showRune2){
    runes2.draw(xPos + 250, yPos, 120, 201);
    }
    if(showRune3){
    runes3.draw(xPos + 250, yPos, 120, 201);
    }
    if(showRune4){
    runes4.draw(xPos + 510, yPos, 120, 201);
    }
    if(showRune5){
    runes5.draw(xPos + 500, yPos, 120, 201);
    }
    if(showRune6){
    runes6.draw(xPos + 750, yPos, 120, 201);
    }
    if(showRune7){
    runes7.draw(xPos + 750, yPos, 120, 201);
    }
}

void Item::drawCantthink(){
    ofSetColor(255,255,255,255);
    if(thinkStage ==1){
        cantthink1.draw(xPos, yPos);
    } else if(thinkStage ==2){
        cantthink2.draw(xPos, yPos);
    } else if (thinkStage ==3){
        cantthink3.draw(xPos, yPos);
    }
}
void Item::drawWalkTo(){
    ofSetColor(255,255,255,255);
    if(walkToStage ==0){
        walkTo0.draw(xPos, yPos, 1991, 512);
    } else if(walkToStage ==1){
        walkTo1.draw(xPos, yPos, 1991, 512);
    } else if (walkToStage ==2){
        walkTo2.draw(xPos, yPos, 1991, 512);
    } else if(walkToStage ==3){
        walkTo3.draw(xPos, yPos, 1991, 512);
    }
    
    if (idle == false){
        if (walkToStage ==0){
            walkToStage = 1;
        }
    }
    cout << "idle: " << idle << endl;
}