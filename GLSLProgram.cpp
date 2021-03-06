#include "GLSLProgram.h"
#include "Error.h"
#include <fstream>
#include <vector>

GLSLProgram::GLSLProgram() : _numAttributes(0), _programID(0), _vertexShaderID(0), _fragmentShaderID(0) // Initilization list for private variables of class
{
}

GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::compileShaders(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath){
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0){
		fatalError("Vertex shader failed to be created!");
	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0){
		fatalError("Fragment shader failed to be created!");
	}

	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);

	std::cout << "Program shader ID: " << _programID << std::endl;

}

void GLSLProgram::compileShader(const std::string &filePath, GLuint id){
	
	// Vertex and fragment shaders are successfully compiled.
	//Now time to link them together into a program.
	//Get a program object.
	_programID = glCreateProgram();

	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()){
		perror(filePath.c_str());
		fatalError("Failed to open " + filePath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(vertexFile, line)){
		fileContents += line + "\n";
	}

	vertexFile.close();

	const char* contetsPtr = fileContents.c_str();
	glShaderSource(id, 1, &contetsPtr, nullptr);

	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE){
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);  // Vector (array) of char, the same as string
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(id);

		std::printf("%s\n", &(errorLog[0]));  // Print array of chars as string format
		fatalError("Shader " + filePath + " failed to compile!");
	}

}

void GLSLProgram::linkShaders(){

	//Attach our shaders to our program
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	//Link our program
	glLinkProgram(_programID);

	//Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> infoLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);

		std::printf("%s\n", &(infoLog[0]));
		fatalError("Shader failed to compile!");

		//We don't need the program anymore.
		glDeleteProgram(_programID);

		//Don't leak shaders either.
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);
	}

	//Always detach shaders after a successful link.
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void GLSLProgram::addAtribute(const std::string &attributeName){
	glBindAttribLocation(_programID, _numAttributes, attributeName.c_str());
	_numAttributes++;
}

void GLSLProgram::use(){
	glUseProgram(_programID);
	for (int i = 0; i < _numAttributes; i++){  // We must enable every vertex attribute
		glEnableVertexAttribArray(i);
	}
}

GLuint GLSLProgram::getShaderID(){
	return _programID;
}

void GLSLProgram::unuse(){
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++){  // We must enable every vertex attribute
		glDisableVertexAttribArray(i);
	}
}

void GLSLProgram::updateUniformVariables(GLFWwindow& window){
	
	_camera.move(window);
	
	gTransformationLocation = glGetUniformLocation(_programID, "gTransformation");
  gProjectionLocation = glGetUniformLocation(_programID, "gProjection");
  gViewLocation = glGetUniformLocation(_programID, "gViewMatrix");
  	
	GLint textureLocation = glGetUniformLocation(_programID, "mySampler");
	glUniform1i(textureLocation, 0);
	
  glm::mat4 modelView = setTransformationMatrix(glm::vec3(0,0,0), 0, 0, 0, 1.0f);
	glm::mat4 viewMatrix = setViewMatrix(_camera);
	glm::mat4 projectionMatrix = setProjectionMatrix(90, 512.0f, 512.0f);

  glUniformMatrix4fv(gTransformationLocation, 1, GL_FALSE, glm::value_ptr(modelView));
  glUniformMatrix4fv(gProjectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
  glUniformMatrix4fv(gViewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}