#pragma once //	Protects from circular includes

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
#include "GLSLProgram.h"
#include "Sprite.h"
#include "CTransformationMatrix.h"

enum class GameState {
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();	

private:

	void initSystem();
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();
	void applyTransformation();	

	GLFWwindow* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;
	GLSLProgram _colorProgram;
};
