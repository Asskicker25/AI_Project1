#pragma once

#include <Graphics/Model.h>

class PlayerController : public Model
{

public:

	PlayerController();

	// Inherited via Model
	void Start() override;
	void Update(float deltaTime) override;
	void OnDestroy() override;

private:
	class Pimpl;
	Pimpl* pimpl = nullptr;

};

