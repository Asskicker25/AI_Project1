#include <Graphics/CameraSystem.h>
#include <Graphics/Renderer.h>
#include <Graphics/Timer.h>

#include "ThirdPersonCameraController.h"
#include "PlayerController.h"

ThirdPersonCameraController::ThirdPersonCameraController(PlayerController* playerController)
{
	name = "3rdPersonCamController";
	InitializeEntity(this);
	InputManager::GetInstance().AddListener(this);

	mPlayerController = playerController;
	mMainCamera = CameraSystem::GetInstance().GetMainCamera();

}

#pragma region INPUT

void ThirdPersonCameraController::OnKeyPressed(const int& key)
{
}

void ThirdPersonCameraController::OnKeyReleased(const int& key)
{
}

void ThirdPersonCameraController::OnKeyHeld(const int& key)
{
}

void ThirdPersonCameraController::OnPropertyDraw()
{
	ImGui::SliderFloat("Pitch", &mPitch, -180, 180);
	ImGui::SliderFloat("Yaw", &mYaw, -180, 180);

	ImGui::InputFloat3("Eye Position", &mEyePosition.x);
	ImGui::InputFloat("Camera Speed", &mCameraSpeed);

}

#pragma endregion

void ThirdPersonCameraController::Start()
{
	InitializeCamera();
}

void ThirdPersonCameraController::Update(float deltaTime)
{
	HandleEyePosition();
	HandleCamera();
	HandleInput();
}

void ThirdPersonCameraController::OnDestroy()
{
}

void ThirdPersonCameraController::InitializeCamera()
{

}

void ThirdPersonCameraController::Render()
{
	/*glm::vec3 startPoint = mMainCamera->transform.position;
	glm::vec3 endPoint = startPoint + (mCameraForward * mFollowDistance);

	Renderer::GetInstance().DrawLine(startPoint, endPoint, glm::vec4(0, 0, 1, 1));*/
}

void ThirdPersonCameraController::HandleEyePosition()
{
	mEyePosition = mPlayerController->transform.position + mEyePositionOffset;
}

void ThirdPersonCameraController::HandleCamera()
{
	mCameraForward = CalculateCameraForward();

	glm::vec3 cameraPos = mEyePosition + (-mCameraForward * mFollowDistance);
	
	mMainCamera->transform.SetPosition(cameraPos);

	glm::vec3 up = glm::vec3(0, 1, 0);

	glm::quat rotationQuat = glm::quatLookAt(mCameraForward, up);

	mMainCamera->transform.SetQuatRotation(rotationQuat);
}

void ThirdPersonCameraController::HandleInput()
{
	glm::vec2 currentMousePos = glm::vec2(InputManager::GetInstance().GetMouseX(), InputManager::GetInstance().GetMouseY());
	
	if (mLastMousePos == glm::vec2(0)) { mLastMousePos = currentMousePos; return; }

	mMouseDelta = mLastMousePos - currentMousePos;

	mYaw -= mMouseDelta.x * mCameraSpeed * Timer::GetInstance().deltaTime;
	mPitch += mMouseDelta.y * mCameraSpeed * Timer::GetInstance().deltaTime;

	if (mPitch < -mPitchClampValue) { mPitch = -mPitchClampValue; }
	if (mPitch > mPitchClampValue) { mPitch = mPitchClampValue; }

	mLastMousePos = currentMousePos;
}

glm::vec3 ThirdPersonCameraController::CalculateCameraForward()
{
	glm::vec3 direction;
	direction.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
	direction.y = sin(glm::radians(mPitch));
	direction.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPitch));

	return glm::normalize(direction);
}

