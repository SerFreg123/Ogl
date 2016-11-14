#pragma once
#include "Texture.h"
#include "GL/glew.h"
#include <string>

class ImageLoader{
public:
	static GLTexture loadPNG(std::string filePath);
};