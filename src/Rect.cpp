//
//  Rect.cpp
//  glutapp
//
//  Created by Jefferson Santiago on 11/1/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "../includes/Rect.h"
#include "iostream"

Rect::Rect() : Shape(0,0,1.0,1.0,1.0), width(0.01), height(0.01), checked(false){
    moving = NOT_MOVING;
}


Rect::Rect(float x, float y, float width, float height) : Shape(x, y, 1, 1, 1), width(width), height(height), checked(false){
    moving = NOT_MOVING;
}


Rect::Rect(float x, float y, float width, float height, std::string label) : Shape(x, y, 1, 1, 1), width(width), height(height), checked(false), label(label) {
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


bool Rect::isSelected() const {
    return this->checked;
}

void Rect::select(bool selected) {
    this->checked = selected;
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
    
    
    for (int i = 0; i < myRects.size(); i++) {
        if(myRects[i]->isSelected()) {
            switch (moving) {
                case MOVING_UP:
                    if(myRects[i]->getPosY() > 1.0) {
                        moving = NOT_MOVING;
                    }
                    myRects[i]->setY(myRects[i]->getPosY() + 0.0005);
                    break;
                
                case MOVING_DOWN:
                    if((myRects[i]->getPosY() - myRects[i]->getHeight()) < -1.0) {
                        moving = NOT_MOVING;
                    }
                    myRects[i]->setY(myRects[i]->getPosY() - 0.0005);
                    
                    break;
                
                case MOVING_LEFT:
                    if(myRects[i]->getPosX() < -1.0) {
                        moving = NOT_MOVING;
                    }
                    myRects[i]->setX(myRects[i]->getPosX() - 0.0005);
                    
                    break;
                
                case MOVING_RIGHT:
                    if((myRects[i]->getPosX() + myRects[i]->getWidth())  > 1.0) {
                        moving = NOT_MOVING;
                    }
                    myRects[i]->setX(myRects[i]->getPosX() + 0.0005);
                    
                    break;
                
                default:
                    break;
            }
        }
        collision();

    }

    glutPostRedisplay();
}

void Rect::keyPressDown(unsigned char key, float x, float y) {

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

void Rect::keyPressUp(unsigned char key, float x, float y) {
    std::cout << "test" << std::endl;
    if(moving != NOT_MOVING) {
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

void Rect::mouseDown(int b, int s, float x, float y) const {
    if (b == 0){
        // Left click
        if (s == 0){
            // Left down
            for (int i = 0; i < myRects.size(); i++) {
                if(myRects[i]->contains(x, y)) {
                    std::cout << i << std::endl;
                    myRects[i]->select(true);
                }
                else {
                    myRects[i]->select(false);
                }
            }
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


void Rect::collision() {
    int current = -1;
    //Find slected rectangle;
    for (int i = 0; i < myRects.size(); i++) {
        if(myRects[i]->isSelected()) {
            current = i;
            std::cout << i << std::endl;
        }
        
    }
    //Check if slected has collided with the rest
    for (int i = 0; i < myRects.size(); i++) {

        if(current >= 0 && current != i) {
            // All points of rectangle
            float
                // Get dimensions of current rectangle
                currposX = myRects[i]->getCenterX(),
                currposY = myRects[i]->getCenterY(),
                currwidth = myRects[i]->getWidth(),
                currheight = myRects[i]->getHeight();
            
            // Check if upper border conflicts
            if(myRects[current]->contains(currposX, currposY + currheight/2)) {
                std::cout << "Test 1" << std::endl;
                myRects[current]->select(false);
                moving = NOT_MOVING;
            }
            // Check if lower border conflicts
            else if(myRects[current]->contains(currposX, currposY - currheight/2)) {
                std::cout << "Test 2" << std::endl;
                myRects[current]->select(false);
                moving = NOT_MOVING;
            }
            // Check if left border conflicts
            else if(myRects[current]->contains(currposX - currwidth/2, currposY)) {
                std::cout << "Test 3" << std::endl;
                myRects[current]->select(false);
                moving = NOT_MOVING;
            }
            // Check if right border conflicts
            else if(myRects[current]->contains(currposX + currwidth/2, currposY)) {
                std::cout << "Test 4" << std::endl;
                myRects[current]->select(false);
                moving = NOT_MOVING;
            }
        }
    }
}


Rect::~Rect() {
    for (int i = 0; i < myRects.size(); i++) {
        delete myRects[i];
    }
}
