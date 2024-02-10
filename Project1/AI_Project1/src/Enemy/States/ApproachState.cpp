#include "ApproachState.h"
#include <Graphics/Timer.h>

void ApproachState::Start()
{
	mTarget = &mEnemy->mTarget->transform;
}

void ApproachState::Update()
{
	if (mEnemy->mTarget == nullptr) return;

	HandleDirection();
	HandleRotation();
	HandleMovement();
}

void ApproachState::Cleanup()
{
}

void ApproachState::HandleDirection()
{
	mMoveDir = mTarget->position - mEnemy->transform.position;

	mCurrentDistance = glm::length(mMoveDir);

	if (mCurrentDistance != 0)
	{
		mMoveDir = glm::normalize(mMoveDir);
	}
}

void ApproachState::HandleMovement()
{

	mTowards = mCurrentDistance > mApproachDistance;

	mEnemy->transform.position += mMoveDir * (mTowards ? 1.0f : -1.0f) 
		* mEnemy->mBaseSpeed * Timer::GetInstance().deltaTime;

}

void ApproachState::HandleRotation()
{
	if (mCurrentDistance <= mApproachDistance + 0.1f && mCurrentDistance >= mApproachDistance - 0.1f)
	{
		mTowards = true;
	}

	glm::quat rotationQuat = glm::quatLookAt(mMoveDir * (mTowards ? -1.0f : 1.0f), glm::vec3(0, 1, 0));
	mEnemy->transform.SetQuatRotation(rotationQuat);
}
