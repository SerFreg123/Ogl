#ifndef H_WDOWS_H
#define H_WDOWS_H

#include "GL/glew.h"
#define GLFW_DLL
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <iostream>
#include <string>

class Window{
public:

	Window();

  void setWindow(GLFWwindow*);

  GLFWwindow *getWindow();

private:

  GLFWwindow *_window;

};

#endif