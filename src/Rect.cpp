//
//  Rect.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "../includes/Rect.h"

Rect::Rect() : x(0), y(0), width(0.01), height(0.01), checked(false) {}


Rect::Rect(float x, float y, float width, float height) : x(x) , y(y), width(width), height(height), checked(false) {}


Rect::Rect(float x, float y, float width, float height, std::string label) : x(x) , y(y), width(width), height(height), checked(false), label(label) {}


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
        float   posx = myRects[i]->getPosX(),
                posy = myRects[i]->getPosY(),
                w = myRects[i]->getWidth(),
                h = myRects[i]->getHeight();
        
        
        glBegin(GL_POLYGON);
        
        glVertex2f(posx, posy);
        glVertex2f(posx + w, posy);
        glVertex2f(posx + w, posy - h);
        glVertex2f(posx, posy - h);
        
        glEnd();
    }
    
    
    glutPostRedisplay();
}


Rect::~Rect() {
    for (int i = 0; i < myRects.size(); i++) {
        delete myRects[i];
    }
}
