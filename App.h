#ifndef App_h
#define App_h

#include "GlutApp.h"
#include <vector>
#include "AnimatedRect.h"
#include "Environment.hpp"
#include "Bird.hpp"


class App: public GlutApp {
    static int amount;
    static float rate;
    static float tube_gap;
    
    static const char* pipeFile;
    static const char* background;
    static const char* professor;
    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;
    Environment* game;
    TexRect* back;
    Bird* bird;

public:
    
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    void idle();
    ~App();
    
};
#endif
