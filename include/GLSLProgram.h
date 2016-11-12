#pragma once
#include <iostream>
#include <string>
#include <GL\glew.h>
#include "CTransformationMatrix.h"
#include "Camera.h"

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath);
	void linkShaders();
	void addAtribute(const std::string &attributeName);
	void updateUniformVariables(GLFWwindow& _window);
	GLuint getShaderID();

	void use();
	void unuse();
private:

	int _numAttributes;

	void compileShader(const std::string &filePath, GLuint id);
	GLuint _programID;

	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
	
	Camera _camera;
	
	GLuint gTransformationLocation;
	GLuint gProjectionLocation;
	GLuint gViewLocation;
};