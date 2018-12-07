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


class Bird : private Physics {
    
    TexRect* bird;
    
public:
    Bird(const char* texture);
    ~Bird();
    
    void draw();
};

#endif /* Bird_hpp */
