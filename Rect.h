#ifndef Rect_hpp
#define Rect_hpp

#include "GlutApp.h"


class Rect {
    
private:
    // Location and dimensions of the Rectangle:
    float x;
    float y;
    float width;
    float height;
    bool checked;
    std::string label;
    
public:
    Rect() : x(0), y(0), width(0.01), height(0.01){}
    
    Rect(float x, float y, float width, float height) : x(x) , y(y), width(width), height(height), checked(false){}
    
    Rect(float x, float y, float width, float height, std::string label) : x(x) , y(y), width(width), height(height), checked(false), label(label){}

    float getPosX() const {
        return this->x;
    }
    
    float getPosY() const {
        return this->y;
    }
    
    float getWidth() const {
        return this->width;
    }
    
    float getHeight() const {
        return this->height;
    }
    
    void setX(float x) {
        this->x = x;
    }
    
    void setY(float y) {
        this->y = y;
    }
    
    void setHeight(float height) {
        this->height = height;
    }
    
    void setWidth(float width) {
        this->width = width;
    }
    
    float getCenterX() const {
        return (this->x + (this->width / 2));
    }
    
    float getCenterY() const {
        return (this->y - (this->height / 2));
    }
    
    bool contains(float x, float y) {
        return ((x >= (this->getPosX())) && (x <= this->getPosX() + this->width)  && (y <= this->getPosY()) && (y >= this->getPosY() - this->height));
    }
    
    
    bool isSlotUsed() {
        return this->checked;
    }
    
    
    std::string getLabel() {
        return this->label;
    }
    void draw(){
        glBegin(GL_POINTS);
        
        glVertex2f(x, y);
        glVertex2f(x+width, y);
        glVertex2f(x+width, y-height);
        glVertex2f(x, y-height);
        
        glEnd();
    }
    ~Rect() {
        this->x = 0;
        this->y = 0;
        this->width = 0;
        this->height = 0;
        this->checked = false;
    }
    
};

#endif /* Rect_hpp */
