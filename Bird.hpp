//
//  Bird.hpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/4/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <iostream>
#include "TexRect.h"
#include <vector>
#include "Physics.hpp"


class Bird : public Physics {
    
    TexRect* bird;
    float lift = 0.00025;
    
public:
    Bird(const char* texture);
    ~Bird();
    
    void move();
    void Jump();
    void draw();
    virtual void Fall();
};

#endif /* Bird_hpp */
