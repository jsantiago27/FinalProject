//
//  Labels.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/13/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Labels.hpp"

//(float x, float y, float w, float h, float r, float g, float b): x(x), y(y), w(w), h(h), r(r), g(g), b(b)
Labels::Labels(float x, float y, float w, float h, float r, float g, float b, std::string label) : Rect(x, y, w, h, r, g, b) {
    this->title = label;
}

Labels::~Labels() {
    
}

void Labels::draw() {
    
    glColor3f(0.0, 0.0, 0.0);
    std::string var = this->title;
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x +  0.05, getCenterY());
    //get the length of the string to display
    //loop to display character by character
    for (int i = 0; i < var.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, var[i]);
    }
    
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    
    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);
    
    glEnd();
}


void Labels::setString(std::string newString) {
    this->title = newString;
}
