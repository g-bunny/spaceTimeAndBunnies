#include "ofApp.h"
int height = 20;
int width = 30;

//--------------------------------------------------------------
void ofApp::setup(){
    const ofColor lavender = ofColor(176,183,255);
    const ofColor blue = ofColor(178,255,233);
    const ofColor red = ofColor(242,105,105);

    this->firstFrame = new Frame(lavender, 300, 300, 100, 275, 250);
    this->secondFrame = new Frame(blue, 300, 300, 100, 687.5,250);
    this->thirdFrame = new Frame(red, 300, 300, 100, 1100, 250);
    this->fourthFrame = new Frame(lavender, 1125, 300, 100, 687.5, 625);
    this->one = new Characters(500,478,0,1);
    this->zero = new Characters(350,478,0,2);
    this->timer = new Timer();
    
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofCamera();
//    for (int y = 0; y < height; y++){
//        for(int x = 0; x < width; x++){
//            mesh.addVertex(ofPoint(x,y,0));
//            mesh.addColor(ofFloatColor(0,0,0));
//        }
//    }
//    
//    for (int y = 0; y < height - 1; y++){
//        for (int x = 0; x < width -1 ; x++){
//            mesh.addIndex(x+y*width);
//            mesh.addIndex((x+1)+y*width);
//            mesh.addIndex(x+(y+1)*width);
//            mesh.addIndex((x+1)+y*width);
//            mesh.addIndex((x+1)+(y+1)*width);
//   \\\\\\\ex(x+(y+1)*width);
//        }
//    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    firstFrame->draw();
    secondFrame->draw();
    thirdFrame->draw();
    fourthFrame->draw();
//    secondFrame->lines();
//    zero->display();
    one->display();
    zero->display();
    one->move();
    zero->move();
    
    timer->jumpedTime();
    cout << "one is Player? " << one->isPlayer << endl;
    cout << "one is AI? " << one->isAI << endl;
    cout << "one is one? " << one->isOne << endl;
    cout << "one is zero? " << one->isZero << endl;
    cout << "zero is Player? " << zero->isPlayer << endl;
    cout << "zero is AI? " << zero->isAI << endl;
    cout << "zero is one? " << zero->isOne << endl;
    cout << "zero is zero? " << zero->isZero << endl;
//    secondFrame->keyPressed();
//    secondFrame->keyReleased();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'd'){
        firstFrame->flipRight = true;
    }
    if (key == 'a'){
        firstFrame->flipLeft = true;
    }
    if (key == 'w'){
        firstFrame->flipUp = true;
    }
    if (key == 's'){
        firstFrame->flipDown = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
}
