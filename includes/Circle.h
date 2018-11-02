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
    
    float x;
    float y;
    float rad;

public:
    Circle();
    Circle(float x, float y, float radius);
    ~Circle();
    
    // Getter Functions
    float getPosX() const;
    float getPosY() const;
    float getRad() const;
    
    // Setter Functions
    void setX(float newX);
    void setY(float newY);
    void setRadius(float newRad);
    
    // Add circle functions
    void addCircle();
    void addCircle(float x, float y, float rad);
    
    // Draw function
    void draw() const;
    
    // Miscellaneous functions
    bool contains(float mx, float my) const;

    
};

#endif /* Circle_hpp */
