#include "globalSetting.h"

#include <GL/glfw.h>
#include "cookbookogl.h"
#include "scene.h"
#include "glutils.h"
#include "GUIManager.h"

Scene *guiManager;

void initializeGL() 
{
	// Select OpenGL 4.3 with a forward compatible core profile.
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 4 );
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3 );
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 8);
	// Initialize GLFW &  Open the glfw window with tile name
	if( !glfwInit() ) exit( EXIT_FAILURE );
	if( !glfwOpenWindow( WIN_WIDTH, WIN_HEIGHT, 8,8,8,8,24,0, GLFW_WINDOW ) ) {
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	string title = "GLSL GUI by Yuanfeng Zhu";
	glfwSetWindowTitle(title.c_str());

	//// Load the OpenGL functions.
	if( ogl_LoadFunctions() == ogl_LOAD_FAILED ) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glClearColor(0.2f,0.2f,0.2f,0.0f); 

	// Load a guiManager
	guiManager = new GUIManager();
	if(guiManager==NULL)
		exit( EXIT_FAILURE );
}

void mainLoop() {
	while( glfwGetWindowParam(GLFW_OPENED) && !glfwGetKey(GLFW_KEY_ESC) ) {
		glfwGetWindowSize( &WIN_WIDTH, &WIN_HEIGHT );

		GLUtils::checkForOpenGLError(__FILE__,__LINE__);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
		guiManager->resize(WIN_WIDTH, WIN_HEIGHT);
		TIME=glfwGetTime();
		guiManager->update(TIME);
		guiManager->render();
		glfwSwapBuffers();
	}
}

int main(int argc, char *argv[])
{
	// Initialization
	initializeGL();	

	// Enter the main loop
	mainLoop();

	// Close window and terminate GLFW
	glfwTerminate();
	// Exit program
	exit( EXIT_SUCCESS );
}
