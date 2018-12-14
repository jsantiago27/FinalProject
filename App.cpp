#include <iostream>
#include "App.h"

int App::amount = 5;
float App::rate = 0.0005;
float App::tube_gap = 2.0;
const char *App::pipeFile = "pipe2.png";
const char *App::background = "back.png";
const char *App::professor = "images/Miguel.png";

App::App(int argc, char **argv) : GlutApp(argc, argv)
{

    bird = new Bird(professor);
    game = new Environment(amount, pipeFile, tube_gap);
    back = new TexRect(background, -1.0, 1.0, 2.0, 2.0);
}

void App::draw()
{
    back->draw(0.0);
    bird->draw();
    game->drawPipes();

    redraw();
}

void App::keyDown(unsigned char key, float x, float y)
{
    if (key == 27)
    {
        exit(0);
    }

    if (key == 32)
    {
        std::cout << "Space" << std::endl;
        bird->Jump();
        redraw();
    }
}
void App::idle()
{

    game->move(rate);
    bird->Fall();
}
App::~App()
{
    std::cout << "Exiting..." << std::endl;
    delete game;
}
