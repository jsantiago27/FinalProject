//
//  Environment.cpp
//  glutapp
//
//  Created by Omar Olmos on 12/3/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Environment.hpp"
//Constructors for the environment
Environment::Environment(){
    buildPipes(" ");
}
Environment::Environment(int amount, const char* file): amount(amount){
    buildPipes(file);
    drawPipes();
    
}

//Function to create pipes
void Environment::buildPipes(const char* file){
    //Building top pipes
    std::cout << "Building " << amount << " Top Pipes" << std::endl;
    for(int i = 1; i <= amount; i++){
        topPipes.push_back(new TexRect(file, (1.0 + ((float)i - 0.4)), 1.0, 0.4, 0.5));
    }
    std::cout << "Building " << amount << " Bottom Pipes" << std::endl;
    
    //Building bottom pipes
    for(int i = 1; i <= amount; i++){
        bottomPipes.push_back(new TexRect(file,(1.0 + ((float)i - 0.4)), -1.0, 0.4, -1.0) );
    }
}

void Environment::move(float rate){
    std::cout << "Moving Pipes " << std::endl;

    for(int i = 0; i < amount; i++){
        
        float x = topPipes[i]->getX();
        
        std::cout << x << std::endl;

        topPipes[i]->setX(x - rate);
        x = bottomPipes[i]->getX();
        
        std::cout << x << std::endl;

        bottomPipes[i]->setX(x - rate);
    }
}

void Environment::drawPipes(){
    std::cout << "Drawing Pipes " << std::endl;
    
    for(int i = 0; i < amount; i++){
        topPipes[i]->draw(0.1);
        bottomPipes[i]->draw(0.1);
    }
}

Environment::~Environment(){
    for(int i = 0; i < amount; i++){
        delete topPipes[i];
        delete bottomPipes[i];
    }
}
