#include <iostream>
#include "App.h"

App::App(int argc, char** argv): GlutApp(argc, argv){
    explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    
    fastExplosion = new AnimatedRect("caveman.png", 4, 4, 100, 0.5, 0.5, 0.5, 0.5);
}

void App::draw() {
    explosion->draw(0.15);
    fastExplosion->draw(0.25);
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
        fastExplosion->playOnce();
        explosion->playOnce();
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete explosion;
    delete fastExplosion;
}
