#include <Graphics/Renderer.h>

#include "Enemy.h"
#include "States/IdleState.h"
#include "States/SeekState.h"
#include "States/BaseState.h"


Enemy::Enemy(eEnemyState currentState, std::string modelPath)
{
	mCurrentState = currentState;

	AddState(IDLE, new IdleState());
	AddState(SEEK, new SeekState());

	LoadModel(modelPath);
	transform.SetScale(glm::vec3(0.01f));
	//mModel->transform.SetRotation(glm::vec3(0, 180, 0));
}

void Enemy::AddState(eEnemyState stateKey, BaseState* state)
{
	mListOfStates[stateKey] = state;
	state->mEnemy = this;
}

void Enemy::RemoveState(eEnemyState stateKey)
{
	mListOfStates.erase(stateKey);
}

void Enemy::ChangeState(eEnemyState state)
{
	GetCurrentState()->Cleanup();

	mCurrentState = state;
}

BaseState* Enemy::GetCurrentState()
{
	return mListOfStates[mCurrentState];
}

void Enemy::Start()
{
	std::unordered_map<eEnemyState, BaseState*>::iterator it;

	for (it = mListOfStates.begin(); it != mListOfStates.end(); ++it)
	{
		it->second->Start();
	}
}

void Enemy::Update(float deltaTime)
{
	GetCurrentState()->Update();
}

void Enemy::Render()
{
}

void Enemy::OnDestroy()
{
}
