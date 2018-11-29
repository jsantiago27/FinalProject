#include "App.h"

int main(int argc, char** argv) {
<<<<<<< HEAD
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
    App* myApp = new App("MyApp", 50, 50, 800, 600);
=======
    GlutApp* app = new App(argc, argv);
>>>>>>> d4f33d0c850c7e88fc4cbda8df3258c8e5a4bce0

    app->run();
}
