#pragma once

#include <Graphics/EntityManager/Entity.h>
#include <Graphics/InputManager/InputManager.h>
#include <Graphics/Camera.h>

class PlayerController;

class ThirdPersonCameraController : public Entity, public iInputListener
{
public:
	ThirdPersonCameraController(PlayerController* playerController);

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void OnDestroy() override;
	void Render() override;

	// Inherited via iInputListener
	void OnKeyPressed(const int& key) override;
	void OnKeyReleased(const int& key) override;
	void OnKeyHeld(const int& key) override;

	virtual void OnPropertyDraw();

	PlayerController* mPlayerController = nullptr;

private:

	void InitializeCamera();

	void HandleEyePosition();
	void HandleCamera();
	void HandleInput();

	glm::vec3 CalculateCameraForward();

	float mFollowDistance = 10;
	float mPitch = 0;
	float mYaw = -90;
	float mPitchClampValue = 75.0f;
	float mCameraSpeed = 10.0f;


	glm::vec2 mLastMousePos;
	glm::vec2 mMouseDelta;

	glm::vec3 mEyePosition;
	glm::vec3 mCameraForward = glm::vec3(0,0,-1);
	glm::vec3 mEyePositionOffset = glm::vec3(0,5,0);

	Camera* mMainCamera = nullptr;



};

