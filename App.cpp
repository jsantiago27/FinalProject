#include <iostream>
#include "App.h"

int amount = 5;
int rate = 0.05;

App::App(int argc, char** argv): GlutApp(argc, argv){
    explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    
    fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);
    game = new Environment(amount);
}

void App::draw() {
    
    game->move(rate);

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
