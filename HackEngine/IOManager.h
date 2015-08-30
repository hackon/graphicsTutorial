#pragma once
#include <vector>

class IOManager
{
public:
	static bool readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath);
};

