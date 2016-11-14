#pragma once
#include <vector>
#include <string>

class IOManager{
	
public:
	static bool readFileToBuffer(const std::string &filesPath, std::vector<unsigned char> &bufer);	
};