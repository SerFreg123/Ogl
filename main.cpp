#include "GL/glew.h"
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
#include <vector>
#include "MainGame.h"
#include "Camera.h"
//#include "Magick++.h"

using namespace std;
			
int main()
{   
	 MainGame game;
	 game.run();
   glfwTerminate();
   return 0;
    
}