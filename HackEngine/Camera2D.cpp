#include "Camera2D.h"
#include "HackEngine.h"

namespace HackEngine {

	Camera2D::Camera2D() : _screenWidth(500), _screenHeight(500), _needsMatrixUpdate(1), _scale(1.0f), _position(0.0f, 0.0f), _cameraMatrix(1), _orthoMatrix(1.0f) {

	}

	Camera2D::~Camera2D() {
	}

	void Camera2D::init(int screenWidth, int screenHeight) {
		_screenWidth = screenWidth;
		_screenHeight = screenHeight;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
	}

	void Camera2D::update() {
		if (_needsMatrixUpdate) {
			glm::vec3 translate(-_position.x + _screenWidth / 2, -_position.y + _screenHeight / 2, FLOAT_ZERO);
			_cameraMatrix = glm::translate(_orthoMatrix, translate);

			glm::vec3 scale(_scale, _scale, 0.0f);
			_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;
			_needsMatrixUpdate = false;
		}
	}

	glm::vec2 Camera2D::convertScreen2World(glm::vec2 screenCoords) {
		//invert Y
		screenCoords.y = _screenHeight - screenCoords.y;
		//make 0 center
		screenCoords -= glm::vec2(_screenWidth / 2, _screenHeight / 2);
		//scale
		screenCoords /= _scale;
		//translate
		screenCoords += _position;
		return screenCoords;
	}
}
