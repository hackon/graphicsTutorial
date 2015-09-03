#pragma once

#include <HackEngine/Window.h>
#include <HackEngine/GLSLProgram.h>
#include <HackEngine/Camera2D.h>
#include <HackEngine/InputManager.h>
#include "Level.h"
#include "Player.h"

enum class GameState {
	PLAY,
	EXIT
};

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

	void initLevel();

    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void gameLoop();

	void updateAgents();

    /// Handles input processing
    void processInput();

    /// Renders the game
    void drawGame();

    /// Member Variables
	HackEngine::Window _window; ///< The game window
    
	HackEngine::GLSLProgram _textureProgram; ///< The shader program

	HackEngine::InputManager _inputManager; ///< Handles input

	HackEngine::Camera2D _camera; ///< Main Camera

	HackEngine::SpriteBatch _agenSpriteBatch; ///< Draws all agents

	std::vector<Level*> _levels;

	int _screenWidth, _screenHeight;

	GameState _gameState;

	int _fps;

	int _currentLevel;

	std::vector<Human*> _humans;
	std::vector<Zombie*> _zombies;
	Player* _player;
};

