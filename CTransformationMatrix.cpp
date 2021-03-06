#include "CTransformationMatrix.h"

glm::mat4 setTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale){
  glm::mat4 transformationMatrix;
  transformationMatrix = glm::translate(transformationMatrix, translation);
  transformationMatrix = glm::rotate(transformationMatrix,glm::radians(rx), glm::vec3(1.0, 0.0, 0.0));
  transformationMatrix = glm::rotate(transformationMatrix,glm::radians(ry), glm::vec3(0.0, 1.0, 0.0));
  transformationMatrix = glm::rotate(transformationMatrix,glm::radians(rz), glm::vec3(0.0, 0.0, 1.0));
  transformationMatrix = glm::scale(transformationMatrix, glm::vec3(scale , scale , scale));
  return transformationMatrix;
}

glm::mat4 setViewMatrix(Camera camera){
	glm::mat4 viewMatrix;
	viewMatrix = glm::rotate(viewMatrix,glm::radians(camera.getPitch()), glm::vec3(1.0,0.0,0.0));
	viewMatrix = glm::rotate(viewMatrix,glm::radians(camera.getYaw()), glm::vec3(0.0,1.0,0.0));
	glm::vec3 cameraPos = camera.getPosition();
	glm::vec3 negCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
	viewMatrix = glm::translate(viewMatrix, negCameraPos);
	return viewMatrix;
}

glm::mat4 setProjectionMatrix(float fov, float width, float height){	
	glm::mat4 projectionMatrix;
	projectionMatrix = glm::perspective(fov, width / height, 0.1f, 1000.0f);
	std::cout << "FOV: " << fov << std::endl;
	return projectionMatrix;
}