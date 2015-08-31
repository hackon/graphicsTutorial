#include "Window.h"
#include "Errors.h"

namespace HackEngine {
	Window::Window() {
	}

	Window::~Window() {
	}

	int Window::create(std::string windowName, int screenWidth, int sreenHeigth, unsigned currentFlags) {
		Uint32 flags = SDL_WINDOW_OPENGL;

		if (currentFlags & INVISIBLE) {
			flags |= SDL_WINDOW_HIDDEN;
		}
		if (currentFlags & FULLSCREEN) {
			flags |= SDL_WINDOW_FULLSCREEN;
		}
		if (currentFlags & BORDERLESS) {
			flags |= SDL_WINDOW_BORDERLESS;
		}


		_window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, sreenHeigth, flags);
		if (_window == nullptr) {
			fatalError("SDL Window could not be created!");
		}

		//Set up our OpenGL context
		SDL_GLContext glContext = SDL_GL_CreateContext(_window);
		if (glContext == nullptr) {
			fatalError("SDL_GL context could not be created!");
		}

		//Set up glew (optional but recommended)
		GLenum error = glewInit();
		if (error != GLEW_OK) {
			fatalError("Could not initialize glew!");
		}

		printf("*** OpenGL Version: %s ***", glGetString(GL_VERSION));

		//Set the background color to blue
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		//Set VSYNC
		SDL_GL_SetSwapInterval(0);

		return 0;
	}

	void Window::swapBuffer() const {
		SDL_GL_SwapWindow(_window);
	}
}