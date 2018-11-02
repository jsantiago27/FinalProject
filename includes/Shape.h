//
//  Shape.hpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Shape {
    
public:
    // Pure virtual method for draw function
    virtual void draw() const = 0;
    
    // Pure virtual method for contains function
    virtual bool contains(float mx, float my) const = 0;
};

#endif /* Shape_hpp */
