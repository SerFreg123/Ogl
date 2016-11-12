#pragma once
#include <GL\glew.h>
#include <math.h>
#define PI 3.1416
#define ToRadian(x) ((x) * PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / PI)
#define GLFW_DLL
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" 
#include "glm/gtc/type_ptr.hpp" 
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Camera.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init();
	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
	GLuint _iboID;
	GLuint _vaoID;
};

