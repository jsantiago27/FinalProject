#include <iostream>
#include "App.h"

int App::amount = 2;
float App::rate = 0.0005;
float App::tube_gap = 2.0;

#if defined WIN32
const char* App::pipeFile = "pipe2.png";
const char* App::background = "back.png";
const char* App::miguel = "../images/Miguel.png";
const char* App::daniel = "../images/Daniel.png";
const char* App::dongli = "../images/DongLi.png";
const char* App::angelo = "../images/Angelo.png";
const char* App::bird1 = "../images/MLGflappyb.png";
const char* App::bird2 = "../images/flappybirdOG.png";

#elif defined __APPLE__
const char* App::pipeFile = "pipe2.png";
const char* App::background = "back.png";
const char* App::miguel = "images/Miguel.png";
const char* App::daniel = "images/Daniel.png";
const char* App::dongli = "images/DongLi.png";
const char* App::angelo = "images/Angelo.png";
const char* App::bird1 = "images/MLGflappyb.png";
const char* App::bird2 = "images/flappybirdOG.png";

#else
const char* App::pipeFile = "pipe2.png";
const char* App::background = "back.png";
const char* App::miguel = "../images/Miguel.png";
const char* App::daniel = "../images/Daniel.png";
const char* App::dongli = "../images/DongLi.png";
const char* App::angelo = "../images/Angelo.png";
const char* App::bird1 = "../images/MLGflappyb.png";
const char* App::bird2 = "../images/flappybirdOG.png";
#endif

App::App(int argc, char** argv): GlutApp(argc, argv){
    gameStarted = false;
    CSEVersion = false;
    menu.push_back(new Labels(-0.4, 0.5, 0.8, 0.2, 1.0, 1.0, 1.0, "Choose Your Mode"));
    menu.push_back(new Labels(-0.4, 0.2, 0.8, 0.2, 1.0, 1.0, 1.0, "Default"));
    menu.push_back(new Labels(-0.4, -0.1, 0.8, 0.2, 1.0, 1.0, 1.0, "Version"));
    
    score = 0;
    title = NULL;
    scoreBoard = NULL;
}

void App::draw() {
    
    if(gameStarted == false) {
        if(title != NULL) title->draw();
        for (int i = 0; i < menu.size(); i++) {
            menu[i]->draw();
        }
        
        for (int i = 0; i < characterMenu.size(); i++) {
            characterMenu[i]->draw(0.0);
        }
    }
    
    if(gameStarted) {
        if(scoreBoard != NULL) {
            scoreBoard->setString("Score: " + std::to_string(score));
            scoreBoard->draw();
        }
        // Draw the Background
        back->draw(0.0);
        //
        game->move(rate);
        
        // Draw the pipes
        game->drawPipes();
        bird->draw();

    }
    
    redraw();
}

void App::createCharacterMenu() {
    title = new Labels(-0.8, 0.5, 1.6, 0.2, 1.0, 1.0, 1.0, "Choose Your Character!");
    if(CSEVersion == false ){
        characterMenu.push_back(new TexRect(bird1, -0.8, 0, 0.4,0.4));
        characterMenu.push_back(new TexRect(bird2, -0.3, 0, 0.4,0.4));
    }
    else {
        characterMenu.push_back(new TexRect(miguel, -0.7, 0, 0.3,0.3));
        characterMenu.push_back(new TexRect(daniel, -0.3, 0, 0.5,0.5));
        characterMenu.push_back(new TexRect(dongli, 0.1, 0, 0.4,0.4));
        characterMenu.push_back(new TexRect(angelo, 0.4, 0, 0.4,0.4));
    }
    
}

void App::StartGame(const char* character) {
    delete title;
    bird = new Bird(character);
    game = new Environment(amount, pipeFile, tube_gap);
    back = new TexRect(background, -1.0, 1.0, 2.0, 2.0);
    scoreBoard = new Labels(-0.7, 0.98, 0.8, 0.2, 1.0, 0.0, 0.0, "Score: 0");
}

void App::keyDown(unsigned char key, float x, float y){
    
    if (key == 27){
        exit(0);
    }
    if(gameStarted){
    if (key == ' '){
        bird->Jump();
        redraw();
    }
    }
}
        

void App::idle()
{
    if(gameStarted) {
    bird->move();
    }

}


int App::getScore() const {
    return score;
}

void App::addScore() {
    score++;
}

void App::leftMouseDown(float x, float y) {
    
    if(gameStarted == false) {
        for (int i = 0; i < characterMenu.size(); i++) {
            if(characterMenu[i]->contains(x, y)) {
                gameStarted = true;
                StartGame(characterMenu[i]->getFile());
            }
        }
        
        if(!menu.empty()) {
            if(menu[1]->contains(x, y)) {
                std::cout << "Test 1" << std::endl;
                createCharacterMenu();
            }
            if(menu[2]->contains(x, y)) {
                std::cout << "Test 2" << std::endl;
                CSEVersion = true;
                createCharacterMenu();
            }
            for (int i = 0; i < menu.size(); i++) {
                delete menu[i];
            }
            menu.clear();
        }
    }
}


App::~App()
{
    std::cout << "Exiting..." << std::endl;
    delete game;
}
