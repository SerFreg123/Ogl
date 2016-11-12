#include "Vao.h"

Vao::Vao(GLfloat *coordenates, GLuint *index ,size_t sizeC, size_t sizeI) : _id(0), _vbo(0), _ibo(0){
	std::cout << "This is the VAO constructor" << std::endl;
  this->setId(0);
  glGenVertexArrays (1, &_id);
  glBindVertexArray(_id);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->getVbo(coordenates, sizeC));
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->getIbo(index, sizeI));	
}

unsigned int Vao::getVbo(GLfloat *coordenates, size_t size){ 
    glGenBuffers (1, &_vbo);
    glBindBuffer (GL_ARRAY_BUFFER, _vbo);  																			// Traer a foco el buffer
    glBufferData(GL_ARRAY_BUFFER, size, coordenates, GL_STATIC_DRAW);           // Mandar a openGL el buffer
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);                  // Como leer los datos del buffer
    glBindBuffer (GL_ARRAY_BUFFER, 0);
    return _vbo;
}

unsigned int Vao::getIbo(GLuint *index, size_t size){
    glGenBuffers (1, &_ibo);
    glBindBuffer (GL_ARRAY_BUFFER, _ibo);
    glBufferData(GL_ARRAY_BUFFER, size, index, GL_STATIC_DRAW);
	  return _ibo;
}

GLuint Vao::getId(){	
	return _id;
}

void Vao::setId(GLuint id){
	_id = id;
}

void Vao::BindVertexArray(){
	glBindVertexArray(_id);	
}