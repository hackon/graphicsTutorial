#pragma once
#include "GLTexture.h"
#include <string>
namespace HackEngine {
	class ImageLoader
	{
	public:
		static GLTexture loadPng(std::string filePath);
	};
}
