#pragma once
#include <vector>
namespace HackEngine {
	class IOManager
	{
	public:
		static bool readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath);
	};

}