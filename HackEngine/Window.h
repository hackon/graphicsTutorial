#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
namespace HackEngine {
	enum WindowFlags
	{
		INVISIBLE = 0x1,
		FULLSCREEN = 0x2,
		BORDERLESS = 0x4
	};

	class Window
	{
	public:
		Window();
		~Window();

		int create(std::string windowName, int screenWidth, int sreenHeigth, unsigned int currentFlags);

		void swapBuffer();

		int getWidth() { return _width; }
		int getHeight() { return _height; }
	private:
		SDL_Window* _window;
		int _width, _height;
	};

}