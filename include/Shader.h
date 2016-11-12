#include "GL/glew.h"
#define GLFW_DLL
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class shader{
public:

  void init();

  void setShaderProgramme();

  void getShaderProgramme();

  void setvs();

  GLuint getvs();

  void setfs();

  GLuint getfs();

  void attachShader();

private:

  GLuint _shaderProgramme;

  GLuint _vs;

  GLuint _fs;
};