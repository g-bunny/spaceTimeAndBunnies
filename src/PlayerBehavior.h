//
//  PlayerBehavior.h
//  spaceTimeAndBunnies
//
//  Created by Miri Park on 9/23/15.
//
//

#include "ofMain.h"

class PlayerBehavior {
public:
    PlayerBehavior();

    void update();
    void display();
    void initiateTalk();
    void respondTalk();
    
    void walkLeft();
    void walkRight();
    void jump();
    void standLeft();
    void standRight();
    
};