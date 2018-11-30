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
protected:
    // Location and dimensions of the Rectangle:
    float x;
    float y;
    
    // Colors for the rectangle class
    float r;
    float g;
    float b;
    
    
public:
    
    Shape();
    Shape(float x, float y, float r, float g, float b);
    
    virtual ~Shape();
    
    // Pure virtual method for draw function
    virtual void draw() const = 0;
    
    // Pure virtual method for contains function
    virtual bool contains(float mx, float my) const = 0;
    
    // pure virtual method for idle function
    virtual void idle() = 0;
    
    virtual void keyPressDown(unsigned char key, float x, float y) = 0;
    virtual void keyPressUp(unsigned char key, float x, float y) = 0;
    
    virtual void mouseDown(int b, int s, float x, float y) const = 0;
};

#endif /* Shape_hpp */
