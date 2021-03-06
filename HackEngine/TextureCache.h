#pragma once
#include <map>
#include "GLTexture.h"
namespace HackEngine {
	class TextureCache
	{
	public:
		TextureCache();
		~TextureCache();

		GLTexture getTexture(std::string key);
	private:
		std::map<std::string, GLTexture> _textureMap;
	};

}