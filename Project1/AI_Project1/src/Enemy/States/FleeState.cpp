#include "FleeState.h"
#include <Graphics/Timer.h>

void FleeState::Start()
{
	mTarget = &mEnemy->mTarget->transform;
}

void FleeState::OnStateChanged()
{
	mEnemy->meshes[2]->material->AsMaterial()->SetBaseColor(mEnemy->mFleeColor);
	mEnemy->meshes[3]->material->AsMaterial()->SetBaseColor(mEnemy->mFleeColor);
}

void FleeState::Update()
{
	if (mEnemy->mTarget == nullptr) return;

	HandleDirection();
	HandleRotation();
	HandleMovement();
}

void FleeState::Cleanup()
{
}

void FleeState::HandleDirection()
{
	mMoveDir = mEnemy->transform.position - mTarget->position ;

	mCurrentDistance = glm::length(mMoveDir);

	if (mCurrentDistance != 0)
	{
		mMoveDir = glm::normalize(mMoveDir);
	}
}

void FleeState::HandleMovement()
{

	if (!mIsFleeing)
	{
		if (mCurrentDistance <= mFleeAtDistance) 
		{ 
			mIsFleeing = true; 
			return;
		}
	}
	else
	{
		if (mCurrentDistance >= mFleeStopDistance)
		{
			mIsFleeing = false;
			return;
		}

		mEnemy->transform.position += mMoveDir * mEnemy->mRunSpeed * Timer::GetInstance().deltaTime;
	}

}

void FleeState::HandleRotation()
{
	glm::quat rotationQuat = glm::quatLookAt(mMoveDir * (mIsFleeing ? -1.0f : 1.0f), glm::vec3(0, 1, 0));

	mEnemy->transform.SetQuatRotation(rotationQuat);
}


