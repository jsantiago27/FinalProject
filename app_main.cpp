
#include "includes\App.h"

int main(int argc, char** argv) {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of d4f33d0... Merge branch 'master' of https://github.com/jsantiago27/FinalProject
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
<<<<<<< HEAD
    App* myApp = new App("MyApp", 50, 50, 800, 600);
=======
    GlutApp* app = new App(argc, argv);
>>>>>>> d4f33d0c850c7e88fc4cbda8df3258c8e5a4bce0
=======
    App* myApp = new App("MyApp", 50, 50, 600, 600);
>>>>>>> parent of d4f33d0... Merge branch 'master' of https://github.com/jsantiago27/FinalProject

	// Start the app
    myApp->run();
}
