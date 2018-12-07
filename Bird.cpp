//
//  Bird.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/4/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Bird.hpp"

Bird::Bird(const char* texture) {
    bird = new TexRect(texture, -0.8, 0, 0.5, 0.5);
}

Bird::~Bird(){
    
}

void Bird::draw() {
    bird->draw(0.1);
}
