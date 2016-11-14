#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>

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
	
/*	GLfloat coordenates[] = { /////// 3D TRIANGLE
       -1.0f, -1.0f, 0.0f,
        0.0f, -0.5f, 1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
	    }; 
	    

	GLuint index[] = {0,3,1,
										1,3,2,
										2,3,0,
										0,1,2,};*/
										
	Vertex coordenates[4]; 
	
	coordenates[0].position.x = -0.5f;
	coordenates[0].position.y =  0.5f;
	coordenates[0].position.z =  0.0f;
	
	coordenates[1].position.x =  0.5f;
	coordenates[1].position.y =  0.5f;
	coordenates[1].position.z =  0.0f;
	
	coordenates[2].position.x =  0.5f;
	coordenates[2].position.y = -0.5f;
	coordenates[2].position.z =  0.0f;
	
	coordenates[3].position.x = -0.5f;
	coordenates[3].position.y = -0.5f;
	coordenates[3].position.z =  0.0f;
	
	for(int i = 0; i <= 3; i++){
		coordenates[i].color.r = 255;
		coordenates[i].color.g = 0;
		coordenates[i].color.b = 255;
		coordenates[i].color.a = 255;

	}

	
	GLuint index[] = {0,1,2,
										2,3,0,};	
										
	GLfloat UV[] = {
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
	};							

  glGenBuffers (1, &_iboID);
  glBindBuffer (GL_ARRAY_BUFFER, _iboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

	glGenBuffers(1, &_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, _vboID); // Tells GL that want to active this buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(coordenates), coordenates, GL_STATIC_DRAW);

	glGenVertexArrays (1, &_vaoID);
  glBindVertexArray(_vaoID);		// Every time this vao bind its going to bind vbo and ibo
  glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//GLenum error=glGetError(); // GET ERROR FUNCTION
	

	
	/*glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _playerTexture.id);
	glBindTexture(GL_TEXTURE_2D, 0);*/

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboID);
  
  glBindVertexArray(0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

void Sprite::draw(){ 
	
  glBindVertexArray(_vaoID);
  
	//glActiveTexture(GL_TEXTURE0); 
	glDrawRangeElements(GL_TRIANGLES, 0, 3, 6, GL_UNSIGNED_INT, 0);	
}

