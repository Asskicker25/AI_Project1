#pragma once

#include "iInputListener.h"
#include <vector>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>

class InputManager
{
private:
	std::vector<iInputListener*> inputListeners;

	class Pimpl;
	Pimpl* pimpl;

	float mMouseX = 0;
	float mMouseY = 0;

	glm::vec2 mMouseDelta = glm::vec2(0);

public:
	InputManager();
	~InputManager();

	static InputManager& GetInstance();

	void AddListener(iInputListener* inputListener);
	void RemoveListener(iInputListener* inputListener);

	void OnKeyPressed(const int& key);
	void OnKeyReleased(const int& key);
	void OnKeyHeld(const int& key);

	float GetMouseX();
	float GetMouseY();
	glm::vec2 GetMouseDelta();

	void SetMousePos(float x, float y);
	void SetMouseDelta(glm::vec2 delta);
};

