//
//  Shape.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "../includes/Shape.h"

Shape::Shape() : x(0), y(0), r(1), g(1), b(1) {}

Shape::Shape(float x, float y, float r, float g, float b) : x(x), y(y), r(r), g(g), b(b) {}

Shape::~Shape() {
    
}
