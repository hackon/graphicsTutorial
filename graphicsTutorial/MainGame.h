#pragma once

#include <HackEngine/GLSLProgram.h>
#include <HackEngine/Window.h>

#include <HackEngine/SpriteBatch.h>

#include <HackEngine/Camera2D.h>

enum class GameState { PLAY, EXIT };

//Our example game class, just for testing purposes right now
class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	void initSystems();
	void initShaders();
	void gameLoop();
	void processInput();
	void drawGame();
	void calculateFPS();

	HackEngine::Window _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	HackEngine::GLSLProgram _colorProgram;
	HackEngine::Camera2D _camera;

	HackEngine::SpriteBatch _spriteBatch;

	float _fps;
	float _maxFPS;
	float _frameTime;

	float _time;
};

