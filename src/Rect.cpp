//
//  Rect.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "../includes/Rect.h"

Rect::Rect() : x(0), y(0), width(0.01), height(0.01), checked(false), r(1), g(1), b(1) {
    moving = NOT_MOVING;
}


Rect::Rect(float x, float y, float width, float height) : x(x) , y(y), width(width), height(height), checked(false), r(1), g(1), b(1) {
    moving = NOT_MOVING;
}


Rect::Rect(float x, float y, float width, float height, std::string label) : x(x) , y(y), width(width), height(height), checked(false), label(label), r(1), g(1), b(1) {
    moving = NOT_MOVING;
}


void Rect::addRect(float x, float y, float w, float h) {
    myRects.push_back(new Rect(x, y, w, h));
}


void Rect::addRect(float x, float y, float w, float h, std::string label) {
    myRects.push_back(new Rect(x, y, w, h, label));
}

float Rect::getPosX() const {
    return this->x;
}

float Rect::getPosY() const {
    return this->y;
}

float Rect::getWidth() const {
    return this->width;
}

float Rect::getHeight() const {
    return this->height;
}

void Rect::setX(float x) {
    this->x = x;
}

void Rect::setY(float y) {
    this->y = y;
}

void Rect::setHeight(float height) {
    this->height = height;
}

void Rect::setWidth(float width) {
    this->width = width;
}

float Rect::getCenterX() const {
    return (this->x + (this->width / 2));
}

float Rect::getCenterY() const {
    return (this->y - (this->height / 2));
}

bool Rect::contains(float x, float y) const {
    return ((x >= (this->getPosX())) && (x <= this->getPosX() + this->width)  && (y <= this->getPosY()) && (y >= this->getPosY() - this->height));
}


bool Rect::isSlotUsed() const {
    return this->checked;
}


std::string Rect::getLabel() const {
    return this->label;
}


void Rect::draw() const {
    
    
    for (int i = 0; i < myRects.size(); i++) {
        float   red = myRects[i]->getRed(),
                green = myRects[i]->getGreen(),
                blue = myRects[i]->getBlue(),
                posx = myRects[i]->getPosX(),
                posy = myRects[i]->getPosY(),
                w = myRects[i]->getWidth(),
                h = myRects[i]->getHeight();
        
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        
        glVertex2f(posx, posy);
        glVertex2f(posx + w, posy);
        glVertex2f(posx + w, posy - h);
        glVertex2f(posx, posy - h);
        
        glEnd();
    }
    
    
    glutPostRedisplay();
}

void Rect::idle() {
    
    switch (moving) {
        case MOVING_UP:
            
            for (int i = 0; i < myRects.size(); i++) {
                myRects[i]->setY(myRects[i]->getPosY() + 0.0005);
            }
            
            break;
        
        case MOVING_DOWN:
            for (int i = 0; i < myRects.size(); i++) {
                myRects[i]->setY(myRects[i]->getPosY() - 0.0005);
            }
            break;
        
        case MOVING_LEFT:
            for (int i = 0; i < myRects.size(); i++) {
                myRects[i]->setX(myRects[i]->getPosX() - 0.0005);
            }
            break;
        
        case MOVING_RIGHT:
            for (int i = 0; i < myRects.size(); i++) {
                myRects[i]->setX(myRects[i]->getPosX() + 0.0005);
            }
            break;
        
        default:
            break;
    }

    glutPostRedisplay();
}

void Rect::keyPress(unsigned char key, float x, float y) {
    
    if(key == 'w') {
        moving = MOVING_UP;
    }
    if(key == 's') {
        moving = MOVING_DOWN;
    }
    if(key == 'a') {
        moving = MOVING_LEFT;
    }
    if(key == 'd') {
        moving = MOVING_RIGHT;
    }
    if(key == ' ') {
        moving = NOT_MOVING;
    }
    
    glutPostRedisplay();
}

float Rect::getRed() const {
    return this->r;
}
float Rect::getGreen() const {
    return this->g;
}
float Rect::getBlue() const {
    return this->b;
}

void Rect::setRed(float red) {
    this->r = red;
}
void Rect::setGreen(float green) {
    this->g = green;
}
void Rect::setBlue(float blue) {
    this->b = blue;
}


Rect::~Rect() {
    for (int i = 0; i < myRects.size(); i++) {
        delete myRects[i];
    }
}
