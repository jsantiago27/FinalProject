//
//  Environment.cpp
//  glutapp
//
//  Created by Omar Olmos on 12/3/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Environment.hpp"

//Constructors for the environment
Environment::Environment() : amount(0),pipe_offset(0.4), pipe_image(" "){
    buildPipes();
    drawPipes();
}

Environment::Environment(int amount, const char* file, float pipe_offset): amount(amount),  pipe_offset(pipe_offset), pipe_image(file){
    buildPipes();
    drawPipes();
    
}

//Function to create pipes
void Environment::buildPipes(){
    
    std::cout << "Building " << amount << " Top Pipes" << std::endl;
    float randomHeight = 0;
    for(int i = 0; i < amount; i++){
        //Building top pipes
        // Generate random Height for each pipes
        randomHeight = generateHeight(-0.5, 0.5);
        topPipes.push_back(new TexRect(pipe_image, (3.0 + ((float)i*pipe_offset)), 2.0 - randomHeight, 0.5, 1.6));
        bottomPipes.push_back(new TexRect(pipe_image, (3.0 + ((float)i*pipe_offset)), -2.0 - randomHeight, 0.5, -1.6) );
    }
}

void Environment::addPipe(){
    
}
//Randomize the height of the pipes
float Environment::generateHeight(float low, float high) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(low, high);
    
    return dis(gen);
}

//Move the pipes at a set rate
void Environment::move(float rate){
    
    std::cout << "Moving Pipes " << std::endl;
    
    for(int i = 0; i < amount; i++){
        
        float x = topPipes[i]->getX();
        
        topPipes[i]->setX(x - rate);
        x = bottomPipes[i]->getX();
        
        std::cout << x << std::endl;
        
        bottomPipes[i]->setX(x - rate);
        
        //If pipe reaches end, move to end.
        if(topPipes[i]->getX() + topPipes[i]->getW() <= -1.0){
            
        }
    }
}

//Draw pipes
void Environment::drawPipes(){
    std::cout << "Drawing Pipes " << std::endl;
    
    for(int i = 0; i < amount; i++){
        topPipes[i]->draw(0.1);
        bottomPipes[i]->draw(0.1);
    }
}

//Destructor
Environment::~Environment(){
    std::cout << "Deleting " << amount << " Pipes" << std::endl;
    for(int i = 0; i < amount; i++){
        delete topPipes[i];
        delete bottomPipes[i];
    }
}
