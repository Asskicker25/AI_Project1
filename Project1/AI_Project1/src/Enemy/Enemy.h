#pragma once

#include <unordered_map>
#include <Graphics/Model.h>

#include "States/eEnemyState.h"

class BaseState;

class Enemy : public Model
{
public:
	Enemy(eEnemyState currentState, std::string modelPath);

	void AddState(eEnemyState stateKey, BaseState* state);
	void RemoveState(eEnemyState stateKey);
	void ChangeState(eEnemyState state);

	BaseState* GetCurrentState();

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;


private:

	std::unordered_map<eEnemyState, BaseState*> mListOfStates;

	eEnemyState mCurrentState;


};

