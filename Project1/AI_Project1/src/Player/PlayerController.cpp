#include "PlayerController.h"
#include "ThirdPersonCameraController.h"
#include <Graphics/Timer.h>
#include <Graphics/CameraSystem.h>


class PlayerController::Pimpl
{
public:

	float mPlayerSpeed = 10;
	glm::vec2 mMoveDir;

	PlayerController* mPlayerController = nullptr;
	Camera* mMainCamera;

	Pimpl(PlayerController* playerController);

	void Start();
	void Update();
	void OnPropertyDraw();

	void SetInput();
	void HandleMovement();
	void HandleRotation();
};

PlayerController::Pimpl::Pimpl(PlayerController* playerController) : mPlayerController{ playerController }
{
	ThirdPersonCameraController* cameraController = new ThirdPersonCameraController(mPlayerController);
}

PlayerController::PlayerController() : pimpl{ new Pimpl(this) }
{
	LoadModel("Assets/Models/Player.fbx");
	transform.SetScale(glm::vec3(0.01f));
	transform.SetRotation(glm::vec3(0, 180, 0));
	name = "PlayerController";
}

void PlayerController::Start()
{
	pimpl->Start();
}

void PlayerController::Update(float deltaTime)
{
	pimpl->Update();
}

void PlayerController::OnDestroy()
{
}

void PlayerController::OnPropertyDraw()
{
	Model::OnPropertyDraw();

	pimpl->OnPropertyDraw();
}

void PlayerController::Pimpl::Start()
{
	mMainCamera = CameraSystem::GetInstance().GetMainCamera();
}

void PlayerController::Pimpl::Update()
{
	SetInput();
	HandleMovement();
	HandleRotation();
}

void PlayerController::Pimpl::SetInput()
{
	mMoveDir.x = InputManager::GetInstance().GetAxisX();
	mMoveDir.y = InputManager::GetInstance().GetAxisY();

	if (glm::length(mMoveDir) != 0)
	{
		mMoveDir = glm::normalize(mMoveDir);
	}

}

void PlayerController::Pimpl::HandleMovement()
{
	mPlayerController->transform.position += mPlayerController->transform.GetForward() * - mMoveDir.y *
		mPlayerSpeed * Timer::GetInstance().deltaTime;

	mPlayerController->transform.position += mPlayerController->transform.GetRight() * -mMoveDir.x *
		mPlayerSpeed * Timer::GetInstance().deltaTime;
}

void PlayerController::Pimpl::HandleRotation()
{
	glm::vec3 rotation = mPlayerController->transform.rotation;
	
	rotation.y = mMainCamera->transform.rotation.y + 180;

	mPlayerController->transform.SetRotation(rotation);
}

void PlayerController::Pimpl::OnPropertyDraw()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 10));

	ImGui::DragFloat2("MoveDir", &mMoveDir[0]);

	glm::vec3 forwardDir = mPlayerController->transform.GetForward();

	ImGui::DragFloat3("ForwardDir", &forwardDir[0]);

	ImGui::PopStyleVar();
}



