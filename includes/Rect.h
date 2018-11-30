#ifndef Rect_h
#define Rect_h

#include <string>
#include <vector>
#include "Shape.h"

#define NOT_MOVING      0
#define MOVING_UP       1
#define MOVING_DOWN     2
#define MOVING_LEFT     3
#define MOVING_RIGHT    4


class Rect : public Shape {
    
private:
    // vector variable
    std::vector<Rect*> myRects;
    float width;
    float height;
    
    bool checked;
    std::string label;
    
    // misc
    //  0 = not moving
    //  1 = up
    //  2 = down
    //  3 = left
    //  4 = right
    short moving;
    
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
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    
    
    // Setter methods
    void setX(float newX);
    void setY(float newY);
    void setHeight(float newHeight);
    void setWidth(float newWidth);
    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);
    void select(bool selected);
    
    // Miscellaneous methods
    bool contains(float mx, float my) const;
    bool isSelected() const;
    
    // draw methods
    void draw() const;
    
    // idle funcs
    void idle();
    void keyPressDown(unsigned char key, float x, float y);
    void keyPressUp(unsigned char key, float x, float y);
    
    void mouseDown(int b, int s, float x, float y) const;
    
    void collision();
};

#endif /* Rect_hpp */
