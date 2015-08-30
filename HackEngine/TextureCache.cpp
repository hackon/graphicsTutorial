#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>


TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	std::map<std::string, GLTexture>::iterator mit = _textureMap.find(texturePath);
	//auto mit = _textureMap.find(key);

	if (mit == _textureMap.end())
	{
		GLTexture newTexture = ImageLoader::loadPng(texturePath);
		_textureMap.insert(make_pair(texturePath, newTexture));

		std::cout << "Loaded Texture \n";
		return newTexture;
	}

	std::cout << "Loaded cached Texture \n";
	return mit->second;
}