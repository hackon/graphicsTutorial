#pragma once

#include <SDL/SDL.h>

#include <HackEngine/GLSLProgram.h>

#include <HackEngine/Sprite.h>
#include <vector>
#include <HackEngine/Window.h>
#include <HackEngine/Camera2D.h>

enum class GameState
{
	PLAY,
	EXIT
};

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

	std::vector<HackEngine::Sprite*> _sprites;

	HackEngine::GLSLProgram _colorProgram;
	HackEngine::Camera2D _camera;
	float _fps;
	float _maxFps;
	float _frameTime;

	float _time;
};
