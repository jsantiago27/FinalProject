
#include "includes/App.h"

int main(int argc, char** argv) {
<<<<<<< HEAD
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
    App* myApp = new App("MyApp", 50, 50, 800, 600);
=======
    GlutApp* app = new App(argc, argv);
>>>>>>> 8386071ca906b9ad5d4453c6d26404a8918b8187

	// Start the app
    myApp->run();
}
