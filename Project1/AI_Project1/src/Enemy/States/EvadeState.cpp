#include "EvadeState.h"
#include <Graphics/Timer.h>

void EvadeState::Start()
{
	mTarget = &mEnemy->mTarget->transform;
}

void EvadeState::Update()
{
	if (mEnemy->mTarget == nullptr) return;

	HandleDirection();
	HandleMovement();
	HandleRotation();
}

void EvadeState::Cleanup()
{
}

void EvadeState::HandleDirection()
{
	mMoveDir = mEnemy->transform.position - mTarget->position;

	mCurrentDistance = glm::length(mMoveDir);

	if (mCurrentDistance != 0)
	{
		mMoveDir = glm::normalize(mMoveDir);
	}
}

void EvadeState::HandleMovement()
{
	mIsEvading = false;

	if (mCurrentDistance > mEvadeAtDistance) return;

	mEnemy->transform.position += mMoveDir * mEnemy->mRunSpeed * Timer::GetInstance().deltaTime;
	mIsEvading = true;
}

void EvadeState::HandleRotation()
{
	glm::quat rotationQuat = glm::quatLookAt(mMoveDir * (mIsEvading ? -1.0f : 1.0f), glm::vec3(0, 1, 0));
	mEnemy->transform.SetQuatRotation(rotationQuat);

}
