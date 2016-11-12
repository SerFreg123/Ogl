#include "MainGame.h"
#include <iostream>
#include <string>
#include "Error.h"

MainGame::MainGame()
{
	_window = nullptr;
	_screenHeight = 512;
	_screenWidth = 512;
	_gameState = GameState::PLAY;  // Have to give namespace to enum classes
}

void MainGame::run(){
	initSystem();

	// PONER COORDENADAS DE DIBUJO
	_sprite.init();

	gameLoop();
}

void MainGame::initSystem(){
  if(!glfwInit()) fatalError("GLFW could not be initialized!");
	
	_window = glfwCreateWindow(512,512,"Hello Triangles", NULL, NULL);
	
  if(!_window) fatalError("GLFW window could not be created!");
    
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

	initShaders();
}

void MainGame::initShaders(){
	_colorProgram.compileShaders("Shaders/colorShading.vert.txt", "Shaders/colorShading.frag.txt");
	//_colorProgram.addAtribute("vertexPosition");
	_colorProgram.linkShaders();
	_colorProgram.use();
}

void MainGame::gameLoop(){
	while (!glfwWindowShouldClose(_window)){
		processInput();
		drawGame();
		
	}
}

void MainGame::processInput(){
	_colorProgram.updateUniformVariables(*_window);
	//_camera.move(_window);
}

void MainGame::drawGame(){
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//_colorProgram.use();
	_sprite.draw();
	//_colorProgram.unuse();

	glfwPollEvents();
  glfwSwapBuffers(_window);  
}

void MainGame::applyTransformation(){


}

MainGame::~MainGame()
{
}