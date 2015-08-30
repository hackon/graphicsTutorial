#include "ResourceManager.h"

HackEngine::TextureCache HackEngine::ResourceManager::_textureCache;

HackEngine::GLTexture HackEngine::ResourceManager::getTexture(std::string texturePath)
{
	return _textureCache.getTexture(texturePath);
}