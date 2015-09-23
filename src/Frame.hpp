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
    Frame(ofColor frameColor, int boxWidth, int boxHeight, int boxDepth, float marginX, float marginY);
    void draw();
    void lines();
    void rotateMe();
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
    ofColor frameColor;
    bool flipUp = false;
    bool flipDown = false;
    bool flipRight = false;
    bool flipLeft = false;
    
    bool currentFrame;
    
    ofMesh mesh;
    ofMesh triangle;
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
};