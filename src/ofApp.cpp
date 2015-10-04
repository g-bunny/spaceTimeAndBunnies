#include "ofApp.h"


void ofApp::setup(){
//    this->chapter1 = new Chapter1();
    this->chapter7 = new Chapter(4, 300, 300, 100, 275, 250, "chimney", "door");
    this->chapter1 = new Chapter(1, 500, 500, 500, 600, 400, "sign", "door");
}

//--------------------------------------------------------------
void ofApp::update(){
    if (currentChapter == 2){
        chapter7->update();
    } else if (currentChapter == 1){
        chapter1->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (currentChapter == 2){
        chapter7->draw();
    } else if (currentChapter == 1){
        chapter1->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    chapter7->keyPressed(key);
    chapter1->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    chapter1->keyReleased(key);
    chapter7->keyReleased(key);
}
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//}
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//}
////--------------------------------------------------------------
//void ofApp::mousePressed(int x, int y, int button){
////    if (x < ofGetWindowWidth()/2){
////        talk.play();
////        talk.setSpeed(0.1f)
////    }
////    if (x > ofGetWindowWidth()/2 && x < ofGetWindowWidth()){
////        door->interactionInitiated = true;
////    }
//}
////--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    currentChapter+=1;
}
////--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//}
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//}
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){ 
//}
