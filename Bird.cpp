//
//  Bird.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/4/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Bird.hpp"

Bird::Bird(const char* texture) {
    bird = new TexRect(texture, -0.8, 0, 0.3, 0.3);
}

Bird::~Bird(){
    
}

void Bird::move() {
    float y = bird->getY();
    
    velYo += gravity;
    bird->setY(y + velYo);
    std::cout<< bird->getY() << std::endl;
}

void Bird::draw() {
    bird->draw(0.1);
}

float Bird::getX() const {
    return bird->getX();
}

void Bird::Jump() {
    velYo += lift;
}
void Bird::Fall(){
    //bird->setY(bird->getY() - 0.005) ;
   // std::cout << bird->getY() <<  std::endl;

}
