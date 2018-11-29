//
//  Circle.hpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
#include "Shape.h"

class Circle : public Shape {

private:
    std::vector<Circle*> myCircles;
    float rad;
    bool selected;
    
public:
    Circle();
    Circle(float x, float y, float radius);
    ~Circle();
    
    // Getter Functions
    float getPosX() const;
    float getPosY() const;
    float getRad() const;
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    bool isSelected() const;
    
    // Setter Functions
    void setX(float newX);
    void setY(float newY);
    void setRadius(float newRad);
    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);
    void select(bool select);
    
    
    // Add circle functions
    void addCircle();
    void addCircle(float x, float y, float rad);
    
    // Draw function
    void draw() const;
    
    // Idle functions
    void idle();
    
    // Miscellaneous functions
    bool contains(float mx, float my) const;
    
    void keyPressDown(unsigned char key, float x, float y);
    void keyPressUp(unsigned char key, float x, float y);
    
    void mouseDown(int b, int s, float x, float y) const;
    
};

#endif /* Circle_hpp */
