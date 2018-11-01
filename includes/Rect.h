#ifndef Rect_hpp
#define Rect_hpp

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
    float getPosX() const;
    float getPosY() const;
    float getWidth() const;
    float getHeight() const;
    float getCenterX() const;
    float getCenterY() const;
    std::string getLabel() const;
    
    // Setter methods
    void setX(float newX);
    void setY(float newY);
    void setHeight(float newHeight);
    void setWidth(float newWidth);
    
    // Miscellaneous methods
    bool contains(float mx, float my) const;
    bool isSlotUsed() const;
    
    // draw methods
    void draw() const;
};

#endif /* Rect_hpp */
