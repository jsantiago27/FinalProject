#include <iostream>
#include "App.h"

int amount = 5;
float rate = 0.001;
float tube_gap = 2.0;

const char* pipeFile = "pipe2.png";
const char* background = "back.png";


App::App(int argc, char** argv): GlutApp(argc, argv){
    
    game = new Environment(amount, pipeFile, tube_gap);
    back = new TexRect(background, -1.0, 1.0, 2.0, 2.0);
}

void App::draw() {
    back->draw(0.0);
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
