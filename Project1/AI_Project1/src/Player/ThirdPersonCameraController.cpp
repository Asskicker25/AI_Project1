#include "ThirdPersonCameraController.h"

ThirdPersonCameraController::ThirdPersonCameraController()
{
	InitializeEntity(this);
	InputManager::GetInstance().AddListener(this);
}

void ThirdPersonCameraController::Start()
{
}

void ThirdPersonCameraController::Update(float deltaTime)
{
}

void ThirdPersonCameraController::OnDestroy()
{
}

void ThirdPersonCameraController::OnKeyPressed(const int& key)
{
}

void ThirdPersonCameraController::OnKeyReleased(const int& key)
{
}

void ThirdPersonCameraController::OnKeyHeld(const int& key)
{
}
