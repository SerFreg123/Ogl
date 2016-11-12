#ifndef H_MATRIXTRANS_H
#define H_MATRIXTRANS_H

#include "GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" 
#include "glm/gtc/type_ptr.hpp" 
#define GLFW_DLL
#define PI 3.1416
#define ToRadian(x) ((x) * PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / PI)
#include <math.h>
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp" 
#include "glm/gtc/type_ptr.hpp" 
#include "GLFW/glfw3.h"
#include "Camera.h"

glm::mat4 setTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale);
glm::mat4 setViewMatrix(Camera camera);
glm::mat4 setProjectionMatrix(float fov, float width, float height);
	
#endif