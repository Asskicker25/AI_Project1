#include "PursueState.h"
#include <Graphics/Timer.h>

void PursueState::Start()
{
	mTarget = &mEnemy->mTarget->transform;
}

void PursueState::Update()
{
	if (mEnemy->mTarget == nullptr) return;

	HandleDirection();
	HandleRotation();
	HandleMovement();
}

void PursueState::Cleanup()
{
}

void PursueState::HandleDirection()
{
	glm::vec3 mTargetPos = mTarget->position - mTarget->GetForward() * mFuturePredictDistance;

	mMoveDir = mTargetPos - mEnemy->transform.position;

	mCurrentDistance = glm::length(mMoveDir);

	if (mCurrentDistance != 0)
	{
		mMoveDir = glm::normalize(mMoveDir);
	}
}

void PursueState::HandleMovement()
{
	mEnemy->transform.position += mMoveDir * mEnemy->mBaseSpeed * Timer::GetInstance().deltaTime;
}

void PursueState::HandleRotation()
{
	if (mCurrentDistance <= 1) return;

	glm::quat rotationQuat = glm::quatLookAt(-mMoveDir, glm::vec3(0, 1, 0));

	mEnemy->transform.SetQuatRotation(rotationQuat);
}
