//
//  Physics.hpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/4/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Physics_hpp
#define Physics_hpp

#include <iostream>

class Physics {
    float positionY;     // Position of the character
    float velocityY;     // Velocity of the character
    const float gravity;           // How strong is gravity

public:
    Physics();
    ~Physics();
    
    float getGravity();
    virtual void Update(float time);
    
};

#endif /* Physics_hpp */
