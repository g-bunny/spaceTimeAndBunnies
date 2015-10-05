#include "ofApp.h"


void ofApp::setup(){
//    this->chapter1 = new Chapter1();
    this->chapter7 = new Chapter(7, 4, 300, 300, 100, 275, 250, "chimney", "door");
    this->chapter1 = new Chapter(1, 1, 850, 500, 500, 692.5, 425, "sign", "door");
    this->chapter2 = new Chapter(2, 2, 850, 500, 500, 692.5, 425, "sign", "door");
    this->chapter3 = new Chapter(3, 1, 400, 500, 500, 692.5, 425, "sign", "door");
    
    ofTrueTypeFont::setGlobalDpi(72);
    
    chapter7->chapNum = 7;
    chapter1->chapNum = 1;
    chapter2->chapNum = 2;
    chapter3->chapNum = 3;

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
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if (currentChapter == 1){
        chapter1->draw();
    } else if(currentChapter == 2){
        chapter2->draw();
    } else if (currentChapter == 3){
        chapter3->draw();
    } else if (currentChapter == 7){
        chapter7->draw();
    }
    ofSetColor(0);

    cout << chapter7->chapNum << endl;
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
