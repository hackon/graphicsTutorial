#pragma once
#include <string>
#include <GL/glew.h>

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();
	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShaders();

	void addAttribute(const std::string& attributeName);

	void use();
	void unuse();

private:
	std::string getFileContent(const std::string& vertexShaderFilePath);
	void compileShader(const std::string& filePath, GLuint id);
	
	int _numAttributes;

	GLuint _programId;

	GLuint _vertexShaderId;
	GLuint _fragmentShaderId;
};

