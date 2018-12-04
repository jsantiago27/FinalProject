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
#include "Rect.h"
#include <vector>


class Environment{
public:
    std::vector<Rect*> topPipes;
    std::vector<Rect*> bottomPipes;
    int amount = 0;
    
    Environment();
    Environment(int);
    
    void buildPipes();
    void addPipe();
    
    void move(float);
    void drawPipes();
    
};
#endif /* Environment_hpp */
