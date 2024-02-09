#pragma once

#include <Graphics/EntityManager/Entity.h>

class World : public Entity
{
public:

	World();

	void Initialize();
	
	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void OnDestroy() override;
};

