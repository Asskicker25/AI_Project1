#include "World.h"
#include <Graphics/Model.h>


World::World()
{
	name = "World";
	InitializeEntity(this);

	Initialize();
}

void World::Initialize()
{
	Model* floor = new Model("res/Models/DefaultQuad.fbx");
	floor->name = "Floor";
	floor->meshes[0]->material->AsMaterial()->SetBaseColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
	floor->transform.SetPosition(glm::vec3(0, 0, -22.5f));
	floor->transform.SetRotation(glm::vec3(90.0f, 0, 0));
	floor->transform.SetScale(glm::vec3(25.0f));
}

void World::Start()
{
}

void World::Update(float deltaTime)
{
}

void World::OnDestroy()
{
}

void World::Render()
{
}
