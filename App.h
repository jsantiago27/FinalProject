#ifndef App_h
#define App_h

#include "GlutApp.h"
#include <vector>
#include "AnimatedRect.h"
#include "Environment.hpp"

class App: public GlutApp {
    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;
    Environment* game;
    
public:
    
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
