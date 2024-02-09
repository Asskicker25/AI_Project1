#include "PlayerController.h"
#include "ThirdPersonCameraController.h"

class PlayerController::Pimpl
{
public:
	Pimpl(PlayerController* playerController);

	PlayerController* mPlayerController = nullptr;

};

PlayerController::Pimpl::Pimpl(PlayerController* playerController) : mPlayerController{ playerController }
{
	ThirdPersonCameraController* cameraController = new ThirdPersonCameraController(mPlayerController);
}

PlayerController::PlayerController() : pimpl { new Pimpl(this) }
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
}

void PlayerController::OnDestroy()
{
}

