//
//  Circle.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "../includes/Circle.h"

Circle::Circle() : Shape(0, 0, 1, 1, 1), rad(0.03) {}

Circle::Circle(float x, float y, float radius) : Shape(x, y, 1, 1, 1), rad(radius) {}

void Circle::addCircle() {
    myCircles.push_back(new Circle());
}
void Circle::addCircle(float newx, float newy, float newrad) {
    myCircles.push_back(new Circle(newx, newy, newrad));
}

// Getter Functions
float Circle::getPosX() const {
    return this->x;
}
float Circle::getPosY() const {
    return this->y;
}
float Circle::getRad() const {
    return this->rad;
}

// Setter Functions
void Circle::setX(float newX) {
    this->x = newX;
}
void Circle::setY(float newY) {
    this->y = newY;
}

void Circle::setRadius(float newRad) {
    this->rad = newRad;
}

// Draw function
void Circle::draw() const {
    for (int i = 0; i < myCircles.size(); i++) {
        float   red = myCircles[i]->getRed(),
                blue = myCircles[i]->getBlue(),
                green = myCircles[i]->getGreen(),
                posX = myCircles[i]->getPosX(),
                posY = myCircles[i]->getPosY(),
                rad = myCircles[i]->getRad();
        
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        for (float theta = 0; theta < 2 * M_PI; theta += 0.01) {
            
            glVertex2f(posX + (rad * cos(theta)), posY + (rad * sin(theta)));
            glVertex2f(posX + (rad * cos(theta + 0.01)), posY + (rad * sin(theta + 0.01)));
        }
        glEnd();
    }
    
    glutPostRedisplay();
}

void Circle::idle() {
    
    glutPostRedisplay();
}

void Circle::keyPressDown(unsigned char key, float x, float y) {
    glutPostRedisplay();
}

void Circle::keyPressUp(unsigned char key, float x, float y) {
    glutPostRedisplay();
}



float Circle::getRed() const {
    return this->r;
}
float Circle::getGreen() const {
    return this->g;
}
float Circle::getBlue() const {
    return this->b;
}

void Circle::setRed(float red) {
    this->r = red;
}
void Circle::setGreen(float green) {
    this->g = green;
}
void Circle::setBlue(float blue) {
    this->b = blue;
}


void Circle::mouseDown(int b, int s, float x, float y) const {
    if (b == 0){
        // Left click
        if (s == 0){
            // Left down
        }
        else {
            // Left up
        }
    }
    else {
        // Right click
        if (s == 0){
            // Right down
        }
        else {
            // Right up
        }
    }
}



// Miscellaneous functions
bool Circle::contains(float mx, float my) const {
    
    for(int i = 0 ; i < myCircles.size() ; i ++) {
        float a = mx - myCircles[i]->getPosX();
        float b = my - myCircles[i]->getPosY();
        
        float distance = sqrt(pow(a, 2) + pow(b, 2));
        
        if(myCircles[i]->getRad() > distance) {
            return true;
        }
    }
    return false;
}

Circle::~Circle() {
    for (int i = 0; i < myCircles.size(); i++) {
        delete myCircles[i];
    }
}
