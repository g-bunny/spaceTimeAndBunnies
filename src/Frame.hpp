//
//  Frame.hpp
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/19/15.
//
//

#include "ofMain.h"

class Frame{
public:
    Frame(ofColor frontColor, ofColor sideColor, ofColor topColor, int boxWidth, int boxHeight, int boxDepth, float marginX, float marginY, int perspectiveMode);
    void draw();
    void lines();
    void display();
    void rotateMe();
    void proceduralRotation();
    ofBoxPrimitive box;
    ofVboMesh boxSides[ofBoxPrimitive::SIDES_TOTAL];
//    ofVboMesh deformPlane;
//    ofVboMesh topCap, bottomCap, body;
    vector<ofMeshFace> triangles;
    int boxWidth, boxHeight, boxDepth;
    float spinX = 1.0;
    float spinY = 1.0;
    
    float marginX;
    float marginY;
    
    float xStartRatio;
    float yStartRatio;
    ofColor sideColor;
    ofColor topColor;
    ofColor frontColor;
    bool flipUp = false;
    bool flipDown = false;
    bool flipRight = false;
    bool flipLeft = false;
    
    bool currentFrame;
    
    ofMesh linesFront;
    ofMesh linesBack;
    ofMesh linesLeft;
    ofMesh linesRight;
    ofMesh linesTop;
    ofMesh linesBot;
    
    ofMesh faceFront;
    ofMesh faceBack;
    ofMesh faceLeft;
    ofMesh faceRight;
    ofMesh faceTop;
    ofMesh faceBot;
    
    float rotateDegreeX = 0.0;
    float rotateDegreeY = 0.0;
    float rotateDegreeZ = 0.0;
    int xRotateState = 0;
    int yRotateState = 0;
    int zRotateState = 0;
    
    float rotatex = 0.0;
    float rotatey = 0.0;
    float rotatez = 0.0;
    
    float speedOfRotation;
    int perspectiveMode;
};