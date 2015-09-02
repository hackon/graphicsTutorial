#pragma once

#include <HackEngine/Window.h>
#include <HackEngine/GLSLProgram.h>
#include <HackEngine/Camera2D.h>
#include <HackEngine/InputManager.h>

class MainGame
{
public:
    MainGame();
    ~MainGame();

    /// Runs the game
    void run();

private:
    /// Initializes the core systems
    void initSystems();

    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void gameLoop();

    /// Handles input processing
    void processInput();

    /// Renders the game
    void drawGame();

    /// Member Variables
	HackEngine::Window _window; ///< The game window
    
	HackEngine::GLSLProgram _textureProgram; ///< The shader program

	HackEngine::InputManager _inputManager; ///< Handles input

	HackEngine::Camera2D _camera; ///< Main Camera
};

