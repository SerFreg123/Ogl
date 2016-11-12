#include "Sprite.h"

Sprite::Sprite()
{
	_vboID = 0;
	_iboID = 0;
	_vaoID = 0;
}

Sprite::~Sprite()
{
	//if (_vboID) glDeleteBuffers(1, &_vboID);
}

void Sprite::init(){
	
	GLfloat coordenates[] = {
       -1.0f, -1.0f, 0.0f,
        0.0f, -0.5f, 1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
	    }; 

	GLuint index[] = {0,3,1,
										1,3,2,
										2,3,0,
										0,1,2,};


	glGenVertexArrays (1, &_vaoID);
  glBindVertexArray(_vaoID);		// Every time this vao bind its going to bind vbo and ibo

	glGenBuffers(1, &_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, _vboID); // Tells GL that want to active this buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(coordenates), coordenates, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
  glGenBuffers (1, &_iboID);
  glBindBuffer (GL_ARRAY_BUFFER, _iboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vboID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboID);

}

void Sprite::draw(){ 
	
  glBindVertexArray(_vaoID);
	glEnableVertexAttribArray(0);	
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);	
	glDisableVertexAttribArray(0);
}
