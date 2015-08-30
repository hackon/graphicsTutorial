#include "IOManager.h"
#include <fstream>

bool HackEngine::IOManager::readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath)
{
	std::ifstream file(filePath, std::ios::binary);
	if (file.fail())
	{
		perror(filePath.c_str());
		return false;
	}

	file.seekg(0, std::ios::end);
	int fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	fileSize -= file.tellg();

	buffer.resize(fileSize);
	file.read((char *)&buffer[0], fileSize);

	file.close();
	return true;
}