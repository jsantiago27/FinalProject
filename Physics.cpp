//
//  Physics.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/4/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Physics.hpp"

Physics::Physics() : gravity(0.0005), positionY(0), velocityY(0) {
}

Physics::~Physics() {
    
}

void Physics::Update(float time) {
    
}


float Physics::getGravity() {
    return gravity;
}
