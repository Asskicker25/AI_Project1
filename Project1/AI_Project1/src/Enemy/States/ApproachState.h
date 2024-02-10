#pragma once

#include "BaseState.h"

class ApproachState : public BaseState
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

	bool mTowards = false;

	float mCurrentDistance = 0;
	float mApproachDistance = 5.0f;

	glm::vec3 mMoveDir;


	// Inherited via BaseState
	void OnStateChanged() override;

};

