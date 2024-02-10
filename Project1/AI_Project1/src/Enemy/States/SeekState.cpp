#include "SeekState.h"
#include <iostream>
#include <Graphics/Timer.h>

void SeekState::Start()
{
	mTarget = &mEnemy->mTarget->transform;
}

void SeekState::Update()
{
	if (mEnemy->mTarget == nullptr) return;

	HandleDirection();
	HandleRotation();
	HandleMovement();

}

void SeekState::Cleanup()
{
}

void SeekState::HandleDirection()
{
	mMoveDir = mTarget->position - mEnemy->transform.position;

	if (glm::length(mMoveDir) != 0)
	{
		mMoveDir = glm::normalize(mMoveDir);
	}
}

void SeekState::HandleMovement()
{
	mEnemy->transform.position += mMoveDir * mEnemy->mBaseSpeed * Timer::GetInstance().deltaTime;
}

void SeekState::HandleRotation()
{
	glm::quat rotationQuat = glm::quatLookAt(-mMoveDir, glm::vec3(0,1,0));

	mEnemy->transform.SetQuatRotation(rotationQuat);
}
