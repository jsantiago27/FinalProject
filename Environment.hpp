//
//  Environment.hpp
//  glutapp
//
//  Created by Omar Olmos on 12/3/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include "TexRect.h"
#include <vector>


class Environment{
public:
    std::vector<TexRect*> topPipes;
    std::vector<TexRect*> bottomPipes;
    
    int amount = 0;
    
    Environment();
    Environment(int, const char*);
    
    void buildPipes(const char*);
    void addPipe();
    
    void move(float);
    void drawPipes();
    
    ~Environment();
    
};
#endif /* Environment_hpp */
