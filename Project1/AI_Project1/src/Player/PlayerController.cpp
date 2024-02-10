#include "PlayerController.h"
#include "ThirdPersonCameraController.h"



class PlayerController::Pimpl
{
public:

	glm::vec2 mMoveDir;
	PlayerController* mPlayerController = nullptr;

	Pimpl(PlayerController* playerController);

	void Update();
	void SetInput();
	void OnPropertyDraw();

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

void PlayerController::Pimpl::Update()
{
	SetInput();
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

void PlayerController::Pimpl::OnPropertyDraw()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 10));

	ImGui::DragFloat2("MoveDir", &mMoveDir[0]);

	ImGui::PopStyleVar();
}



