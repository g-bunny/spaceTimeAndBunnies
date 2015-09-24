#include "ofApp.h"
int height = 20;
int width = 30;

//--------------------------------------------------------------
void ofApp::setup(){
    const ofColor lavender = ofColor(176,183,255);
    const ofColor blue = ofColor(178,255,233);
    const ofColor red = ofColor(242,105,105);

    this->firstFrame = new Frame(lavender, blue, blue, 300, 300, 100, 275, 250, 1);
    this->secondFrame = new Frame(lavender, lavender, blue, 300, 300, 300, 687.5,250, 1);
    this->thirdFrame = new Frame(lavender, blue, red, 300, 300, 100, 1100, 250, 1);
    this->fourthFrame = new Frame(lavender, red, red, 1125, 300, 100, 687.5, 625, 2);
    this->one = new Characters(200,248,0,1);
    this->zero = new Characters(1070,540,0,2);
    this->timer = new Timer();
    this->brickChimney = new Item(2, 1050, 296);
    this->door = new Item(2,1030,540);
    talk.loadSound("sounds/talk.wav");
    talk.setVolume(0.75f);
    talk.setMultiPlay(true);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofCamera();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    firstFrame->display();
    secondFrame->display();
    thirdFrame->display();
    fourthFrame->display();
    
    firstFrame->draw();
    secondFrame->draw();
    thirdFrame->draw();
    fourthFrame->draw();
//    secondFrame->lines();
//    zero->display();
    if (door->interactionInitiated == true){
        door->drawOpen();
    }
    one->display();
    zero->display();
    one->move();
    zero->move();
    brickChimney->drawChimney();
    if (door->interactionInitiated == false){
        door->drawClosed();
    }
    
    
    
    timer->jumpedTime();
//

    cout << "movementSpeed " << one->movementSpeed << endl;
    cout << "location.x " << one->location.x << endl;
    cout << "door open? " << door->interactionInitiated << endl;
//    cout << "one is zero? " << one->isZero << endl;
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
        if (one->location.x > 100 && one->location.x<400){
            firstFrame->flipRight = true;
        } else if (one->location.x > 500 && one->location.x< 800){
            secondFrame->flipRight = true;
        } else if (one->location.x > 900 && one->location.x < 1200){
            thirdFrame->flipRight = true;
        }
    }
    if (key == 'a'){
        if (one->location.x > 100 && one->location.x<400){
            firstFrame->flipLeft = true;
        } else if (one->location.x > 500 && one->location.x< 800){
            secondFrame->flipLeft = true;
        } else if (one->location.x > 900 && one->location.x < 1200){
            thirdFrame->flipLeft = true;
        }
    }
    if (key == 'w'){
        if (one->location.x > 100 && one->location.x<400){
            firstFrame->flipUp = true;
        } else if (one->location.x > 500 && one->location.x< 800){
            secondFrame->flipUp = true;
        } else if (one->location.x > 900 && one->location.x < 1200){
            thirdFrame->flipUp = true;
        }
    }
    if (key == 's'){
        if (one->location.x > 100 && one->location.x<400){
            firstFrame->flipDown = true;
        } else if (one->location.x > 500 && one->location.x< 800){
            secondFrame->flipDown = true;
        } else if (one->location.x > 900 && one->location.x < 1200){
            thirdFrame->flipDown = true;
        }
    }
    if (key == OF_KEY_RIGHT){
        one->moveRight = false;
    }
    if (key == OF_KEY_LEFT){
        one->moveLeft = false;
    }
    if (key == OF_KEY_UP){
        one->moveUp = false;
    }
    if (key == OF_KEY_DOWN){
        one->moveDown = false;
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
    if (x < ofGetWindowWidth()/2){
        talk.play();
//        talk.setSpeed(0.1f)
    }
    if (x > ofGetWindowWidth()/2 && x < ofGetWindowWidth()){
        door->interactionInitiated = true;
    }
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
