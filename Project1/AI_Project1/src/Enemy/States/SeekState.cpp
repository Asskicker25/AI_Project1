#include "SeekState.h"
#include <iostream>
#include <Graphics/Timer.h>

void SeekState::Start()
{
	mTarget = &mEnemy->mTarget->transform;
}


void SeekState::OnStateChanged()
{
	mEnemy->meshes[2]->material->AsMaterial()->SetBaseColor(mEnemy->mSeekColor);
	mEnemy->meshes[3]->material->AsMaterial()->SetBaseColor(mEnemy->mSeekColor);
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

	mCurrentDistance = glm::length(mMoveDir);

	if (mCurrentDistance != 0)
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
	if (mCurrentDistance < 0.1f) return;

	glm::quat rotationQuat = glm::quatLookAt(-mMoveDir, glm::vec3(0,1,0));

	mEnemy->transform.SetQuatRotation(rotationQuat);
}

