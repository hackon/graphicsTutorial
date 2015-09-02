#include "InputManager.h"

namespace HackEngine {

	InputManager::InputManager() : _mouseCoords(0)
	{
	}


	InputManager::~InputManager()
	{
	}

	void InputManager::pressKey(unsigned keyId) {
		_keyMap[keyId] = true;
	}

	void InputManager::releaseKey(unsigned keyId) {
		_keyMap[keyId] = false;
	}

	bool InputManager::isKeyPressed(unsigned keyId) {
		auto it = _keyMap.find(keyId);
		if (it != _keyMap.end())
		{
			return it->second;
		}
		return false;
	}

	void InputManager::setMouseCoords(float x, float y) {
		_mouseCoords.x = x;
		_mouseCoords.y = y;
	}
}