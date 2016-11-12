#ifndef H_VAO_H
#define H_VAO_H

#include "GL/glew.h"
#define GLFW_DLL
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Vao{
public:
	
	Vao(GLfloat*, GLuint* ,size_t, size_t);
	
	unsigned int getIbo(GLuint*, size_t);
	
	unsigned int getVbo(GLfloat*, size_t);
	
	GLuint getId();
	
	void setId(GLuint);
	
	void BindVertexArray();

private:
	GLfloat _coordenates;

  GLuint _index;

  size_t _sizeCoordenates;

  size_t _sizeIndex;
  
  GLuint _id;
  
  GLuint _vbo;
  
  GLuint _ibo;
  
};

#endif