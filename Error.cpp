#include "Error.h"
#include <cstdlib>
#include <iostream>
#include "GLFW/glfw3.h"

void fatalError(std::string errorString){
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit... ";
	int tmp;
	std::cin >> tmp;
	glfwTerminate();
	exit(1);
}