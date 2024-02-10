#pragma once

#include "BaseState.h"

class PursueState : public BaseState
{

public:
	// Inherited via BaseState
	void Start() override;
	void Update() override;
	void Cleanup() override;

private:

	void HandleDirection();
	void HandleMovement();
	void HandleRotation();

	Transform* mTarget = nullptr;

	float mFuturePredictDistance = 5;
	float mCurrentDistance = 0;

	glm::vec3 mMoveDir;
};

