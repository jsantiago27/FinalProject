#include "../includes/App.h"
#include "SOIL.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
    // initialize my Rects;
    myRects = new Rect();
    
    // initialize myCirc
    myCircs = new Circle();
    
    myRects->addRect(0.0, 0.0, 0.3, 0.3);
    myRects->addRect(0.5, 0.5, 0.3, 0.3);
    myCircs->addCircle(-0.6, 0.3, 0.2);
    
    
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    
    texture = SOIL_load_OGL_texture
    (
     "space.gif",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    if( 0 == texture )
    {
        printf( "SOIL loading error:'\n");
    }    // Set up the transformations stack
    
    
    myRects[0].drawTexturedRect(texture);
    // Draw a yellow cross
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINES);
    
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);
    
    glEnd();
    
    glColor3d(1.0, 0.0, 1.0);

    //myRects->draw();
    myCircs->draw();
    
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    myRects->mouseDown(0, 0, mx, my);
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPressDown(unsigned char key, float x, float y) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
    
    myRects->keyPressDown(key, x, y);
}

void App::keyPressUp(unsigned char key, float x, float y) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
    
    myRects->keyPressUp(key, x, y);
}


void App::idle() {
    
    myRects->idle();
    myCircs->idle();
    
    redraw();
}
