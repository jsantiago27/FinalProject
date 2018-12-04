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
    buildPipes();
}
Environment::Environment(int amount): amount(amount){
    buildPipes();
    drawPipes();
    
}

//Function to create pipes
void Environment::buildPipes(){
    //Building top pipes
    std::cout << "Building " << amount << " Top Pipes" << std::endl;
    for(int i = 1; i <= amount; i++){
        topPipes.push_back(new Rect(1 + (i - 0.4), 1, 0.3, 0.4, 1,1,0.0));
    }
    std::cout << "Building " << amount << " Bottom Pipes" << std::endl;
    
    //Building bottom pipes
    for(int i = 1; i <= amount; i++){
        bottomPipes.push_back(new Rect(1 + (i - 0.4) , -1, -0.3, -0.4, 1,0.0,1));
    }
}

void Environment::move(float rate){
    std::cout << "Moving Pipes " << std::endl;

    for(int i = 1; i <= amount; i++){
        int x = topPipes[i - 1]->getX();
        topPipes[i - 1]->setX(x - rate);
        x = bottomPipes[i - 1]->getX();
        bottomPipes[i - 1]->setX(x - rate);
    }
    drawPipes();
}

void Environment::drawPipes(){
    std::cout << "Drawing Pipes " << std::endl;
    
    for(int i = 1; i <= amount; i++){
        topPipes[i - 1]->draw();
        bottomPipes[i - 1]->draw();
    }

    
}
