#include "ofApp.h"


void ofApp::setup(){
//    this->chapter1 = new Chapter1();
    this->chapter7 = new Chapter(7, 4, 300, 300, 100, 275, 250, 300,300,300,687.5,250,300,300,100,1100,250,1125,300,100,687.5,625);
    this->chapter1 = new Chapter(1, 1, 850, 500, 500, 692.5, 425,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    this->chapter2 = new Chapter(2, 2, 100, 100, 10, 100, 100,100,100,10,300,100,0,0,0,0,0,0,0,0,0,0);
    this->chapter3 = new Chapter(3, 1, 400, 500, 500, 692.5, 425,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

    ofTrueTypeFont::setGlobalDpi(72);
    fileName = "screen1.png";
    chapter7->chapNum = 7;
    chapter1->chapNum = 1;
    chapter2->chapNum = 2;
    chapter3->chapNum = 3;
    
    chapter7->frameWidth2 = 300;
    chapter7->frameHeight2 = 300;
    chapter7->frameWidth3 = 300;
    chapter7->frameHeight3 = 300;
    chapter7->frameDepth2 = 300;
    chapter7->frameDepth3 = 100;
    chapter7->frameWidth4 = 1125;
    chapter7->frameHeight4 = 300;
    chapter7->frameDepth4 = 100;
    chapter7->marginX2 = 687.5;
    chapter7->marginY2 = 250;
    chapter7->marginX3 = 1100;
    chapter7->marginY3 = 250;
    chapter7->marginX4 = 687.5;
    chapter7->marginY4 = 625;
    
    chapter3->frameWidth2 = 300;
    chapter3->frameHeight2 = 300;
    chapter3->frameWidth3 = 300;
    chapter3->frameHeight3 = 300;
    chapter3->frameDepth2 = 300;
    chapter3->frameDepth3 = 100;
    chapter3->marginX2 = 687.5;
    chapter3->marginY2 = 250;
    chapter3->marginX3 = 1100;
    chapter3->marginY3 = 250;
    
    
    chapter2->frameWidth2 = 100;
    chapter2->frameHeight2 = 100;
    chapter2->frameDepth2 = 10;
    chapter2->marginX2 = 300;
    chapter2->marginY2 = 100;
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
    cout << "chapter: " << currentChapter << endl;
    cout << "frames: " << chapter2->numOfFrames << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    chapter7->keyPressed(key);
    chapter1->keyPressed(key);
    chapter2->keyPressed(key);
    chapter3->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    chapter1->keyReleased(key);
    chapter2->keyReleased(key);
    chapter3->keyReleased(key);
    chapter7->keyReleased(key);

}
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//}
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//}
////--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    ofSaveScreen(fileName);
//    capture.loadImage("screen1.png");
//    if (x < ofGetWindowWidth()/2){
//        talk.play();
//        talk.setSpeed(0.1f)
//    }
//    if (x > ofGetWindowWidth()/2 && x < ofGetWindowWidth()){
//        door->interactionInitiated = true;
//    }
}
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
