#include "Shader.h"

shader::shader(const char* vertex_shader,const char* fragment_shader){
	
	  this->setvs();
    glShaderSource(_vs, 1, &vertex_shader, NULL);
    glCompileShader(_vs);

    this->setfs();
    glShaderSource (_fs, 1, &fragment_shader, NULL);
    glCompileShader(_fs);
    
    this->setShaderProgramme();
    this->attachShader();
    
    glUseProgram(_shaderProgramme);	
}

void shader::setShaderProgramme(){

    _shaderProgramme = glCreateProgram();

}

GLuint shader::getShaderProgramme(){

    return _shaderProgramme;

}

void shader::setvs(){

    _vs = glCreateShader (GL_VERTEX_SHADER);

}

GLuint shader::getvs(){

    return _vs;

}

void shader::setfs(){

    _fs = glCreateShader(GL_FRAGMENT_SHADER);

}

GLuint shader::getfs(){

    return _fs;

}

void shader::attachShader(){

    glAttachShader(_shaderProgramme, this->getfs());
    glAttachShader(_shaderProgramme, this->getvs());
    glLinkProgram(_shaderProgramme);

}

