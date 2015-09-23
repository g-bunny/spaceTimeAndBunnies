//
//  Item.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/20/15.
//
//

#include "ofMain.h"

class Item{
public:
    Item(int itemType);
    void draw();
    void lines();
    
    //0 - cube type; 1 - collectible type; 2 - interaction type; 3 - noCollider type; 4 - collider type
    int itemType;
    
    //    void keyPressed();
    //    void keyReleased();
    ofBoxPrimitive box;
    ofVboMesh boxSides[ofBoxPrimitive::SIDES_TOTAL];
    ofVboMesh deformPlane;
    ofVboMesh topCap, bottomCap, body;
    vector<ofMeshFace> triangles;
    int boxSize;
    float spinX = 1.0;
    float spinY = 1.0;
    
    float xStartRatio;
    float yStartRatio;
    ofColor frameColor;
    bool rotateUp = false;
    bool rotateDown = false;
    bool rotateRight = false;
    bool rotateLeft = false;
    
    bool currentFrame;
    
    ofMesh mesh;
    float rotateDegreeX = 0.0;
    float rotateDegreeY = 0.0;
    float rotateDegreeZ = 0.0;
    
//    const ofIndexType Faces[];
//    const float Verts[];
    ofVec3f v[12];
    ofVec3f n[12];
    ofFloatColor c[12];
    
    //door
    bool isDoor;
    bool isCube;
    bool isClock;
    bool isLadder;
    
    //
    
};