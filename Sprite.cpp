#include "Sprite.h"
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
	
	coordenates[0].setPosition(-1.0f, 1.0f, 0.0f);
	coordenates[0].setUV(0.0f, 1.0f);
	
	coordenates[1].setPosition(0.0f,  1.0f, 0.0f);
	coordenates[1].setUV(1.0f, 1.0f);
	
	coordenates[2].setPosition(0.0f,  0.0f, 0.0f);
	coordenates[2].setUV(1.0f, 0.0f);
	
	coordenates[3].setPosition(-1.0f, 0.0f, 0.0f);
	coordenates[3].setUV(0.0f, 0.0f);
	
	for(int i = 0; i <= 3; i++){
		coordenates[i].setColor(255, 0, 255, 255);

	}
	
	GLuint index[] = {0,1,2,
										2,3,0,};	
										
	setIbo(&index[0], sizeof(index));	
  setVbo(&coordenates[0], sizeof(coordenates));	
	_playerTexture = ImageLoader::loadPNG("Textures/PNG/wizard_ice/attack_2.png");
		
	setVao();
}

void Sprite::draw(){ 
	
  glBindVertexArray(_vaoID);
	glDrawRangeElements(GL_TRIANGLES, 0, 3, 6, GL_UNSIGNED_INT, 0);	
}

void Sprite::setVbo(Vertex *coordenates, size_t size){
	glGenBuffers(1, &_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, _vboID); 
	glBufferData(GL_ARRAY_BUFFER, size, coordenates, GL_STATIC_DRAW);
}

void Sprite::setIbo(GLuint *index, size_t size){
	glGenBuffers (1, &_iboID);
  glBindBuffer (GL_ARRAY_BUFFER, _iboID);
  glBufferData(GL_ARRAY_BUFFER, size, index, GL_STATIC_DRAW);
}

void Sprite::setVao(){
	glGenVertexArrays (1, &_vaoID);
  glBindVertexArray(_vaoID);		
  glBindBuffer(GL_ARRAY_BUFFER, _vboID);
  
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _playerTexture.id);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//GLenum error=glGetError(); // GET ERROR FUNCTION
	
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboID);
  
  glBindVertexArray(0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
}

