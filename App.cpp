#include <iostream>
#include "App.h"

int amount = 5;
float rate = 0.0005;

const char* pipeFile = "pipe2.png";


App::App(int argc, char** argv): GlutApp(argc, argv){
    
    game = new Environment(amount, pipeFile);
}

void App::draw() {
    
    game->move(rate);
    game->drawPipes();
    redraw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    
    if (key == ' '){
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete game;
}
