#pragma once

#include "BaseState.h"

class FleeState : public BaseState
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

	bool mIsFleeing = false;

	float mFleeAtDistance = 5;
	float mFleeStopDistance = 15;
	float mCurrentDistance = 0;

	glm::vec3 mMoveDir;
	

	// Inherited via BaseState
	void OnStateChanged() override;

};

