#include "AI_Application.h"
#include "Player/PlayerController.h"
#include "World/World.h"
#include "Enemy/Enemy.h"

void AI_Application::SetUp()
{
	viewportCamera->InitializeCamera(PERSPECTIVE, windowWidth, windowHeight, 0.1f, 500.0f, 45.0f);
	viewportCamera->transform.SetPosition(glm::vec3(0, 10, 10));
	viewportCamera->transform.SetRotation(glm::vec3(-15, 0, 0));
	Renderer::GetInstance().renderMode = SHADED;

	imGuiPanelEnable = true;

	GameCamera* mainCamera = new GameCamera();
	mainCamera->InitializeCamera(PERSPECTIVE, gameResolutionWidth, gameResolutionHeight, 0.1f, 100.0f, 45.0f);
	mainCamera->transform.SetPosition(glm::vec3(0, 3.22f, 7.0f));
	mainCamera->transform.SetRotation(glm::vec3(-13.20, 0, 0.0f));

	Light* dirLight = new Light();
	dirLight->intensity = 0.9f;
	dirLight->transform.SetScale(glm::vec3(0.1f));
	dirLight->transform.SetPosition(glm::vec3(0, 0, 3));
	dirLight->InitializeLight(Directional);

	World* world = new World();

	PlayerController* playerController = new PlayerController();

	glm::vec3 enemyPositions[5] = {
		glm::vec3(-10,0,-40),
		glm::vec3(-20, 0, -20),
		glm::vec3(20,0,-20),
		glm::vec3(0,0,-20),
		glm::vec3(10,0,-40)

	};

	for (int i = 0; i < 5; i++)
	{
		Enemy* enemy = new Enemy(playerController, eEnemyState(i+1), "Assets/Models/Enemy.fbx");
		enemy->name = "Enemy_" + std::to_string(i);
		enemy->transform.SetPosition(enemyPositions[i]);
	}
}

void AI_Application::Update()
{
}

void AI_Application::Render()
{
}

void AI_Application::ProcessInput(GLFWwindow* window)
{
}

void AI_Application::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
}

void AI_Application::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}
