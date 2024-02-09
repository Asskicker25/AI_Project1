#include "PlayerController.h"
#include "ThirdPersonCameraController.h"

class PlayerController::Pimpl
{
public:
	Pimpl();

};

PlayerController::Pimpl::Pimpl()
{
	ThirdPersonCameraController* cameraController = new ThirdPersonCameraController();
}

PlayerController::PlayerController() : pimpl { new Pimpl() }
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

