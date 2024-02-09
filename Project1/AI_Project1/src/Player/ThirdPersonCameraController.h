#pragma once

#include <Graphics/EntityManager/Entity.h>
#include <Graphics/InputManager/InputManager.h>

class ThirdPersonCameraController : public Entity, public iInputListener
{
public:

	ThirdPersonCameraController();

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void OnDestroy() override;

	// Inherited via iInputListener
	void OnKeyPressed(const int& key) override;
	void OnKeyReleased(const int& key) override;
	void OnKeyHeld(const int& key) override;
};

