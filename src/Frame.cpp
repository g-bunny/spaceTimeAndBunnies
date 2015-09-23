//
//  Frame.cpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/19/15.
//
//

#include "Frame.hpp"



Frame::Frame(ofColor frameColor, int boxWidth, int boxHeight, int boxDepth, float marginX, float marginY){
    this->frameColor = frameColor;
    this->boxWidth = boxWidth;
    this->boxHeight = boxHeight;
    this->boxDepth = boxDepth;
    this->marginX = marginX;
    this->marginY = marginY;
//    box = *new ofBoxPrimitive(boxWidth -1, boxHeight - 1, boxDepth-1, 1,1,1);
    mesh = *new ofMesh();
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    mesh.enableColors();
    
    ofVec3f frontTopLeft (-boxWidth/2,-boxHeight/2, boxDepth/2);
    ofVec3f frontTopRight (boxWidth/2,-boxHeight/2, boxDepth/2);
    ofVec3f frontBotLeft (-boxWidth/2, boxHeight/2, boxDepth/2);
    ofVec3f frontBotRight (boxWidth/2, boxHeight/2, boxDepth/2);
    
    ofVec3f backBotRight(boxWidth/2, boxHeight/2, -boxDepth/2);
    ofVec3f backBotLeft(-boxWidth/2, boxHeight/2, -boxDepth/2);
    ofVec3f backTopLeft(- boxWidth/2, -boxHeight/2, -boxDepth/2);
    ofVec3f backTopRight(boxWidth/2, -boxHeight/2, -boxDepth/2);
    
    mesh.addVertex(frontTopLeft);
//    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
    mesh.addVertex(frontTopRight);
//    mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));
    mesh.addVertex(frontBotRight);
//    mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
    mesh.addVertex(frontBotLeft);
//    mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));
    mesh.addVertex(frontTopLeft);
    mesh.addVertex(backTopLeft);
    mesh.addVertex(backBotLeft);
    mesh.addVertex(frontBotLeft);
    mesh.addVertex(frontBotRight);
    mesh.addVertex(backBotRight);
    mesh.addVertex(backBotLeft);
    mesh.addVertex(backTopLeft);
    mesh.addVertex(backTopRight);
    mesh.addVertex(backBotRight);
    mesh.addVertex(backTopRight);
    mesh.addVertex(frontTopRight);
    
        triangle = *new ofMesh();
    
    triangle.addVertex(frontTopLeft);
    triangle.addVertex(frontBotLeft);
    triangle.addVertex(frontTopRight);
    
    triangle.addVertex(frontBotRight);
    triangle.addVertex(frontTopRight);
    triangle.addVertex(frontBotLeft);
    
    triangle.addVertex(frontTopLeft);
    triangle.addVertex(frontTopRight);
    triangle.addVertex(backTopRight);
    
    triangle.addVertex(frontTopLeft);
    triangle.addVertex(backTopLeft);
    triangle.addVertex(backTopRight);
    
    triangle.addVertex(frontBotLeft);
    triangle.addVertex(frontBotRight);
    triangle.addVertex(backBotRight);
    
    triangle.addVertex(frontBotLeft);
    triangle.addVertex(backBotLeft);
    triangle.addVertex(backBotRight);
    
    triangle.addVertex(backTopLeft);
    triangle.addVertex(backBotLeft);
    triangle.addVertex(backTopRight);
    
    triangle.addVertex(backBotRight);
    triangle.addVertex(backTopRight);
    triangle.addVertex(backBotLeft);
    
    triangle.addVertex(frontTopRight);
    triangle.addVertex(frontBotRight);
    triangle.addVertex(backBotRight);
    
    triangle.addVertex(frontTopRight);
    triangle.addVertex(backTopRight);
    triangle.addVertex(backBotRight);
    
    triangle.addVertex(frontTopLeft);
    triangle.addVertex(frontBotLeft);
    triangle.addVertex(backBotLeft);
    
    triangle.addVertex(frontTopLeft);
    triangle.addVertex(backTopLeft);
    triangle.addVertex(backBotLeft);
    
    speedOfRotation = 4.0;
}

//void Frame::setup(){
//    
//    
//}

void Frame::draw(){
    ofPushMatrix();
    ofTranslate(marginX,marginY);
    box.setPosition(0, 0,0);
    ofRotate(rotatey,0.0,1.0,0.0);
    ofRotate(rotatex,1.0,0.0,0.0);
    ofRotate(rotatez,0.0,0.0,1.0);

//    if (rotateRight){
//        rotateDegreeY += 1;
////        box.rotate(spinY, 0.0, 1.0, 0.0);
//        if (rotateDegreeY > 88 && rotateDegreeY < 91){
//            rotateDegreeY = 90;
//        }
//    }
//    if (rotateLeft){
//        rotateDegreeY -=1;
//    }
//    if (rotateUp){
//        rotateDegreeX +=1;
//
//    }
//    if (rotateDown){
//        rotateDegreeX -=1;
//    }
//    
//    //    box.rotate(spinX, 1.0, 0.0, 0.0);
//    vector<ofMeshFace> triangles = box.getMesh().getUniqueFaces();
    ofSetColor(0,0,0);

    ofSetColor(frameColor);
    triangle.draw();
    ofSetColor(0,0,0);
    mesh.draw();

//    box.draw();
//    box.drawWireframe();
//    ofRotate(rotateDegreeY,0.0,1.0,0.0);
//    ofRotate(rotateDegreeX,1.0,0.0,0.0);
//    ofRotate(rotateDegreeZ,0.0,0.0,1.0);
    ofSetColor(0);
    ofPopMatrix();
//
//    keyPressed();
//    keyReleased();
    rotateMe();
}

void Frame::lines(){
    
}

void Frame::rotateMe(){
    if (flipUp == true){
        if (xRotateState == 0){
            rotatex -= speedOfRotation;
            if (rotatex <= -90){
                rotatex = -90;
                flipUp = false;
                xRotateState = 1;
            }
        }
        else if (xRotateState == 1){
            rotatex -= speedOfRotation;
            if (rotatex <= -180){
                rotatex = -180;
                flipUp = false;
                xRotateState = 2;
            }
        }
        else if (xRotateState == 2){
            rotatex -= speedOfRotation;
            if (rotatex <= -270){
                rotatex = -270;
                flipUp = false;
                xRotateState = 3;
            }
        }
        else if (xRotateState == 3){
            rotatex -= speedOfRotation;
            if (rotatex <= -360){
                rotatex = 0;
                flipUp = false;
                xRotateState = 0;
            }
        }
    }
    if (flipDown == true){
        if (xRotateState ==0){
            rotatex += speedOfRotation;
            if(rotatex >=90){
                rotatex = -270;
                flipDown = false;
                xRotateState = 3;
            }
        }
        else if(xRotateState == 3){
            rotatex += speedOfRotation;
            if(rotatex >= -180){
                rotatex = -180;
                flipDown = false;
                xRotateState = 2;
            }
        }
        else if(xRotateState == 2){
            rotatex += speedOfRotation;
            if (rotatex >= -90){
                rotatex = -90;
                flipDown = false;
                xRotateState = 1;
            }
        }
        else if(xRotateState == 1){
            rotatex +=speedOfRotation;
            if (rotatex >=0){
                rotatex = 0;
                flipDown = false;
                xRotateState = 0;
            }
        }
    }
    if (flipLeft == true){
        if (yRotateState ==0){
            rotatey += speedOfRotation;
            if(rotatey >=90){
                rotatey = -270;
                flipLeft = false;
                yRotateState = 3;
            }
        }
        else if(yRotateState == 3){
            rotatey += speedOfRotation;
            if(rotatey >= -180){
                rotatey = -180;
                flipLeft = false;
                yRotateState = 2;
            }
        }
        else if(yRotateState == 2){
            rotatey += speedOfRotation;
            if (rotatey >= 90){
                rotatey = -90;
                flipLeft = false;
                yRotateState = 1;
            }
        }
        else if(yRotateState == 1){
            rotatey +=speedOfRotation;
            if (rotatey >=0){
                rotatey = 0;
                flipLeft = false;
                yRotateState = 0;
            }
        }
    }
    if (flipRight == true){
        if (yRotateState == 0){
            rotatey -= speedOfRotation;
            if (rotatey <= -90){
                rotatey = -90;
                flipRight = false;
                yRotateState = 1;
            }
        }
        else if (yRotateState == 1){
            rotatey -= speedOfRotation;
            if (rotatey <= -180){
                rotatey = -180;
                flipRight = false;
                yRotateState = 2;
            }
        }
        else if (yRotateState == 2){
            rotatey -= speedOfRotation;
            if (rotatey <= -270){
                rotatey = -270;
                flipRight = false;
                yRotateState = 3;
            }
        }
        else if (yRotateState == 3){
            rotatey -= speedOfRotation;
            if (rotatey <= -360){
                rotatey = 0;
                flipRight = false;
                yRotateState = 0;
            }
        }
    }
}
