#ifndef Rect_h
#define Rect_h

#include <string>
#include <vector>
#include "Shape.h"

class Rect : public Shape {
    
private:
    // vector variable
    std::vector<Rect*> myRects;
    
    // Location and dimensions of the Rectangle:
    float x;
    float y;
    float width;
    float height;
    bool checked;
    std::string label;
    
public:
    
    // Constructors
    Rect();
    Rect(float x, float y, float width, float height);
    Rect(float x, float y, float width, float height, std::string label);
    
    // Destructors
    ~Rect();
    
    // Add a rectangle
    void addRect(float x, float y, float width, float height);
    void addRect(float x, float y, float width, float height, std::string label);
    
    // Getter methods
    virtual float getPosX() const;
    virtual float getPosY() const;
    virtual float getWidth() const;
    virtual float getHeight() const;
    virtual float getCenterX() const;
    virtual float getCenterY() const;
    std::string getLabel() const;
    
    // Setter methods
    virtual void setX(float newX);
    virtual void setY(float newY);
    virtual void setHeight(float newHeight);
    virtual void setWidth(float newWidth);
    
    // Miscellaneous methods
    virtual bool contains(float mx, float my) const;
    virtual bool isSlotUsed() const;
    
    // draw methods
    virtual void draw() const;
};

#endif /* Rect_hpp */
