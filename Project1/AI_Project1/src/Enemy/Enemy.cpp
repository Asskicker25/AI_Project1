#include <Graphics/Renderer.h>

#include "Enemy.h"

#include "States/BaseState.h"
#include "States/IdleState.h"
#include "States/SeekState.h"
#include "States/FleeState.h"
#include "States/PursueState.h"



Enemy::Enemy(Entity* target, eEnemyState currentState, const std::string& modelPath)
{
	mTarget = target;

	mCurrentState = currentState;

	AddState(IDLE, new IdleState());
	AddState(SEEK, new SeekState());
	AddState(FLEE, new FleeState());
	AddState(PURSUE, new PursueState());

	LoadModel(modelPath);
	transform.SetScale(glm::vec3(0.01f));
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

void Enemy::OnPropertyDraw()
{
	Model::OnPropertyDraw();

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 150);
	ImGui::Text("State");
	ImGui::NextColumn();

	int item_current = (int)mCurrentState;

	if (ImGui::Combo("###State", &item_current, items, IM_ARRAYSIZE(items)))
	{
		mCurrentState = eEnemyState(item_current);
	}
}
