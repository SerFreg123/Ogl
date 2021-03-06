#ifndef H_CAMERA_H
#define H_CAMERA_H

#include "glm/glm.hpp"

class Camera{
public:

	Camera(): _pitch(0), _yaw(0){
		_position = glm::vec3(0,0,1); 

	}

	Camera(glm::vec3 position): _pitch(0), _yaw(0){
		_position = position;
	}

  void setPosition(glm::vec3 position){
  	_position = position;
  }
  
  glm::vec3 getPosition(){
  	return _position;
  }
  
  void setPitch(float pitch){
  	_pitch = pitch;
  }
  
  float getPitch(){
  	return _pitch;
  }
  
  void setYaw(float yaw){
  	_yaw = yaw;
  }
  
  float getYaw(){
  	return _yaw;
  }
  
void move(GLFWwindow& window)
	{
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_W))
			_position.z -=0.001;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_D))
			_position.x +=0.001;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_A))
			_position.x -=0.001;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_S))
			_position.z+=0.001;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_R))
			_yaw+= 0.1;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_Q))
			_pitch+= 0.1;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_E))
			_pitch-= 0.1;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_F))
			_position.y += 0.001;
		if(GLFW_PRESS == glfwGetKey(&window, GLFW_KEY_G))
			_position.y -= 0.001;
			
		/*if(GLFW_PRESS == glfwGetCursorPos(window, GLFW_KEY_W, ))
			_position.z -=0.001;
		if(GLFW_PRESS == glfwGetCursorPos(window, GLFW_KEY_D, ))
			_position.x +=0.001;
		if(GLFW_PRESS == glfwGetCursorPos(window, GLFW_KEY_A, ))
			_position.x -=0.001;
		if(GLFW_PRESS == glfwGetCursorPos(window, GLFW_KEY_S, ))
			_position.z+=0.001;
		if(GLFW_PRESS == glfwGetCursorPos(window, GLFW_KEY_F, ))
			_position.y += 0.001;
		if(GLFW_PRESS == glfwGetCursorPos(window, GLFW_KEY_G, ))
			_position.y -= 0.001;*/
} 

private:

  glm::vec3 _position;
  
  float _pitch;
  
  float _yaw;

};

#endif