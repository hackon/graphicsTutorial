#pragma once
#include "GLTexture.h"
#include <string>

class ImageLoader
{
public:
	static GLTexture loadPng(std::string filePath);
};

