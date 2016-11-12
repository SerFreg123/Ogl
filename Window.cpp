#include "Window.h"

Window::Window(){
	
  if(!glfwInit()) {
    fprintf (stderr, "ERROR: could not start GLFW2\n");
    //exit(1);
	}
	
	_window = glfwCreateWindow(512,512,"Hello Triangles", NULL, NULL);
	
    if(!_window){
    	
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        //exit(1);
    } 
    
  glfwMakeContextCurrent(_window);
  
  glewExperimental= GL_TRUE;
  glewInit();

  const GLubyte *renderer = glGetString(GL_RENDERER);
  const GLubyte *version = glGetString(GL_VERSION);

  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // sizeof(ARRAY)/sizeof(ARRAY[0])
	
}

GLFWwindow *Window::getWindow(){
	return _window;	
}