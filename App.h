#ifndef App_h
#define App_h

#include "GlutApp.h"
#include <vector>
#include "AnimatedRect.h"
#include "Environment.hpp"
#include "Bird.hpp"
#include "Labels.hpp"


class App: public GlutApp {
    static int amount;
    static float rate;
    static float tube_gap;
    
    static const char* pipeFile;
    static const char* background;
    static const char* miguel;
    static const char* daniel;
    static const char* angelo;
    static const char* dongli;
    
    static const char* bird1;
    static const char* bird2;
    
    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;
    Environment* game;
    TexRect* back;
    Bird* bird;
    
    std::vector<Labels*> menu;
    Labels* title;
    
    std::vector<TexRect*> characterMenu;
    
    bool gameStarted;
    bool CSEVersion;

public:
    
    App(int argc, char** argv);
    
    void createCharacterMenu();
    void StartGame(const char*);
    
    void draw();
    
    void idle();
    
    void keyDown(unsigned char key, float x, float y);
    
    void leftMouseDown(float, float);
    ~App();
    
};
#endif
