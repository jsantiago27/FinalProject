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
<<<<<<< HEAD
    bool selected;
<<<<<<< HEAD
    
=======
>>>>>>> d4f33d0c850c7e88fc4cbda8df3258c8e5a4bce0
=======

>>>>>>> parent of d4f33d0... Merge branch 'master' of https://github.com/jsantiago27/FinalProject
public:
    Circle();
    Circle(float x, float y, float radius);
    ~Circle();
    
    // Getter Functions
    float getPosX() const;
    float getPosY() const;
    float getRad() const;
<<<<<<< HEAD
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    bool isSelected() const;
=======
>>>>>>> parent of d4f33d0... Merge branch 'master' of https://github.com/jsantiago27/FinalProject
    
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
